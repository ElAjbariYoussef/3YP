#include <WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>
#include <ArduinoJson.h>

#define DHTPIN 15
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

const char* ssid = "NOM_WIFI";
const char* password = "MOT_DE_PASSE";

const char* mqtt_server = "192.168.1.10";
const int mqtt_port = 1883;

const char* topic = "smartroom/measurements";

WiFiClient espClient;
PubSubClient client(espClient);

unsigned long previousMillis = 0;
const unsigned long interval = 5000;

void connectWiFi() {

WiFi.begin(ssid, password);

Serial.print("Connexion Wi-Fi");

while (WiFi.status() != WL_CONNECTED) {
delay(500);
Serial.print(".");
}

Serial.println("Wi-Fi connecte !");
Serial.println(WiFi.localIP());
}

void reconnectMQTT() {

while (!client.connected()) {

Serial.println("Connexion MQTT...");

if (client.connect("ESP32_01")) {

Serial.println("MQTT connecte !");

} else {

Serial.print("Erreur MQTT : ");
Serial.println(client.state());

delay(3000);
}
}
}

void setup() {

Serial.begin(115200);

dht.begin();

connectWiFi();

client.setServer(mqtt_server, mqtt_port);
}

void loop() {

if (WiFi.status() != WL_CONNECTED) {
connectWiFi();
}

if (!client.connected()) {
reconnectMQTT();
}

client.loop();

if (millis() - previousMillis >= interval) {

previousMillis = millis();

float temperature = dht.readTemperature();
float humidity = dht.readHumidity();

if (isnan(temperature) || isnan(humidity)) {
Serial.println("Erreur DHT22");
return;
}

JsonDocument doc;

doc["device_id"] = "ESP32_01";
doc["temperature"] = temperature;
doc["humidity"] = humidity;
doc["location"] =  "Salle TP";
doc["sensor_type"] =  "DHT22";
doc["counter"] =  "1";
doc["status"] =  "OK";

String message;

serializeJson(doc, message);

bool published = client.publish(
topic,
message.c_str()
);

Serial.println(message);

Serial.println(
published ? "Publication reussie" :
"Echec publication"
);
}
}