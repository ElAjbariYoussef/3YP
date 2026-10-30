#include <WiFi.h>
#include <HTTPClient.h>
#include "DHT.h"
#include <ArduinoJson.h>

#define DHTPIN 17
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

const char* ssid = "Wifi";
const char* password = "psswd";

const char* serverURL = "http://10.198.217.139:3000/api/measurements";

const char* deviceId = "ESP32_01";
const char* location = "Salle TP1";
const char* sensorType = "DHT22";

unsigned long previousMillis = 0;
const unsigned long interval = 5000;
unsigned long counter = 0;

void sendMeasurements(float temperature, float humidity) {
  JsonDocument doc;

  counter++;

  doc["device_id"] = deviceId;
  doc["temperature"] = temperature;
  doc["humidity"] = humidity;
  doc["location"] = location;
  doc["sensor_type"] = sensorType;
  doc["counter"] = counter;
  doc["status"] = "ACTIVE";

  String jsonData;
  serializeJson(doc, jsonData);

  Serial.println(jsonData);

  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Wi-Fi deconnecte, envoi annule");
    return;
  }

  HTTPClient http;

  http.begin(serverURL);
  http.addHeader("Content-Type", "application/json");

  int code = http.POST(jsonData);

  Serial.print("Code HTTP : ");
  Serial.println(code);

  if (code > 0) {
    Serial.println(http.getString());
  }

  http.end();
}

void setup() {
  Serial.begin(115200);
  dht.begin();

  WiFi.begin(ssid, password);

  Serial.println("Connexion Wi-Fi...");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("Wi-Fi connecte !");
  Serial.println(WiFi.localIP());
}

void loop() {
  if (millis() - previousMillis >= interval) {
    previousMillis = millis();

    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();

    if (isnan(temperature) || isnan(humidity)) {
      Serial.println("Erreur DHT22");
    } else {
      sendMeasurements(temperature, humidity);
    }
  }
}
