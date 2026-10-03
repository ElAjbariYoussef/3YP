#include <WiFi.h>
#include <HTTPClient.h>
#include <DHT.h>
#include "mbedtls/pk.h"
#include "mbedtls/rsa.h"
#include "mbedtls/entropy.h"
#include "mbedtls/ctr_drbg.h"
#include "mbedtls/base64.h"

#define DHTPIN   2
#define DHTTYPE  DHT22
#define LED_PIN  4

// id de l'esp32 envoyer avec le data vers gateway, pour que le gateway puisse distinguer
// cet esp32 avec les autre
const int DEVICE_ID = 1;

const char* ssid     = "nomDuWifi";
const char* password = "motDePasse";

// adresse du Gateway
const char* GATEWAY_URL = "http://192.168.1.100:8080/data";

const char* gatewayPublicKey = R"KEY(
-----BEGIN PUBLIC KEY-----
gatewaypubkey
-----END PUBLIC KEY-----
)KEY";

DHT dht(DHTPIN, DHTTYPE);

// compteur de message pour se protéger du replay attacks
uint32_t msgCounter = 0;

// cryptage du message avec Gateway public key ce message va être décrypter côté Gateway après l'envoie
String encryptWithPublicKey(const String& plain) {
    mbedtls_pk_context pk;
    mbedtls_entropy_context entropy;
    mbedtls_ctr_drbg_context ctr_drbg;
    mbedtls_pk_init(&pk);
    mbedtls_entropy_init(&entropy);
    mbedtls_ctr_drbg_init(&ctr_drbg);
    String result = "";
    const char* pers = "esp32_enc";
    int ret = mbedtls_ctr_drbg_seed(&ctr_drbg, mbedtls_entropy_func, &entropy,
                                    (const unsigned char*)pers, strlen(pers));
    if (ret != 0) goto cleanup;
    ret = mbedtls_pk_parse_public_key(
        &pk,
        (const unsigned char*)gatewayPublicKey,
        strlen(gatewayPublicKey) + 1
    );
    if (ret != 0) {
        Serial.printf("lecture de la clé échouer: -0x%04X\n", -ret);
        goto cleanup;
    }
    mbedtls_rsa_set_padding(mbedtls_pk_rsa(pk), MBEDTLS_RSA_PKCS_V21, MBEDTLS_MD_SHA256);
    {
        unsigned char output[512];
        size_t olen = 0;

        ret = mbedtls_pk_encrypt(
            &pk,
            (const unsigned char*)plain.c_str(), plain.length(),
            output, &olen, sizeof(output),
            mbedtls_ctr_drbg_random, &ctr_drbg
        );
        if (ret != 0) {
            Serial.printf("cryptage échouer: -0x%04X\n", -ret);
            goto cleanup;
        }
        unsigned char b64[800];
        size_t b64len = 0;
        ret = mbedtls_base64_encode(b64, sizeof(b64) - 1, &b64len, output, olen);
        if (ret != 0) goto cleanup;
        b64[b64len] = '\0';
        result = String((char*)b64);
    }
cleanup:
    mbedtls_pk_free(&pk);
    mbedtls_ctr_drbg_free(&ctr_drbg);
    mbedtls_entropy_free(&entropy);
    return result;
}

// lecture cryptage et envoi du data vers Gateway
void sendData() {
    float t = dht.readTemperature();
    float h = dht.readHumidity();
    if (isnan(t) || isnan(h)) {
        // erreur 0 est pour fail de lecture de DHT22
        Serial.println("erreur 0");
        return;
    }
    digitalWrite(LED_PIN, t > 30.0 ? HIGH : LOW);

    msgCounter++;
    String json = "{";
    // id de esp
    json += "\"i\":" + String(DEVICE_ID) + ",";
    // température
    json += "\"t\":" + String(t, 2) + ",";
    // humidité
    json += "\"h\":" + String(h, 2) + ",";
    // compteur de message
    json += "\"n\":" + String(msgCounter);
    json += "}";

    Serial.println("le data avant cryptage:");
    Serial.println(json);

    String encryptedPayload = encryptWithPublicKey(json);

    if (encryptedPayload.length() == 0) {
        Serial.println("cryptage échouer");
        return;
    }
    // envoi vers le Gateway
    HTTPClient http;
    http.begin(GATEWAY_URL);
    http.addHeader("Content-Type", "text/plain");
    int code = http.POST(encryptedPayload);
    Serial.printf("réponse de la Gateway: %d\n", code);
    http.end();
}

void setup() {
    Serial.begin(115200);
    pinMode(LED_PIN, OUTPUT);
    dht.begin();
    WiFi.begin(ssid, password);
    Serial.print("Connection vers le WiFi");
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println();
    Serial.println("Connecter!");
    Serial.print("ESP32 IP: ");
    Serial.println(WiFi.localIP());
}

void loop() {
    sendData();
    delay(10000);
}