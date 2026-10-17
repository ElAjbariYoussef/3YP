#include <WiFi.h>
#include <WebServer.h>
#include <WebSocketsServer.h>

const int VERT = 2;
const int ROUGE = 5;
const int BOUTON = 33;
const int LDR = 34;
const char* SSID = "";
const char* passwd = "";
bool arme = LOW;
bool dernierEtat = HIGH;

WebSocketsServer webSocket(81);

void onWebSocketEvent(uint8_t client,WStype_t type,uint8_t* payload,size_t length) {
    switch (type) {
        case WStype_CONNECTED:
            webSocket.sendTXT(client, "Connected to ESP32");
            break;

        case WStype_DISCONNECTED:
            Serial.println("Browser disconnected");
            break;

        case WStype_TEXT: {
            String message;
            for (size_t i = 0; i < length; i++) {
                message += (char)payload[i];
            }
            if (message == "{\"command\":\"setArmed\",\"value\":true}") {
                arme = true;
            } else if (message == "{\"command\":\"setArmed\",\"value\":false}") {
                arme = false;
            }
            break;
        }
        default:
            break;
    }
}


void setup() {
    Serial.begin(115200);
    pinMode(BOUTON, INPUT_PULLUP);
    pinMode(VERT, OUTPUT);
    pinMode(ROUGE, OUTPUT);

    WiFi.begin(SSID, passwd);
    Serial.print("Connected");
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println(WiFi.localIP());

    webSocket.begin();
    webSocket.onEvent(onWebSocketEvent);
}

void loop() {
    if (WiFi.status() != WL_CONNECTED) {
        Serial.println("Reconnecting...");
        WiFi.reconnect();
        delay(100);
        return; 
    }

    bool etat = digitalRead(BOUTON);
    int lum = map(analogRead(LDR), 0, 4095, 100, 0);
    if (dernierEtat == HIGH && etat == LOW) {
        arme = !arme;
        delay(50);
    }
    dernierEtat = etat;
    digitalWrite(VERT, LOW);
    digitalWrite(ROUGE, LOW);
    if (!arme && lum < 50) {
        digitalWrite(ROUGE, HIGH);
    } else if (!arme) {
        digitalWrite(VERT, HIGH);
    }

    bool red = digitalRead(ROUGE);
    bool green = digitalRead(VERT);

    Serial.printf(
        "Arme: %s | Rouge: %s | Vert: %s\n",
        arme ? "true" : "false",
        red ? "true" : "false",
        green ? "true" : "false"
    );

    String json = "{";
    json += "\"arme\":" + String(arme ? "true" : "false") + ",";
    json += "\"red\":" + String(red ? "true" : "false") + ",";
    json += "\"green\":" + String(green ? "true" : "false");
    json += "}";

    webSocket.broadcastTXT(json);

    webSocket.loop();
    
    delay(100);
}