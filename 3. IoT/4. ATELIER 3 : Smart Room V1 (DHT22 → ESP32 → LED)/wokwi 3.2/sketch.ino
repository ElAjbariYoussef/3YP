#include "DHT.h"
#define DHTPIN 4
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

void setup() { Serial.begin(115200); dht.begin(); }

void loop() {
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  Serial.print("Temperature: "); Serial.print(t); Serial.print(" °C ");
  Serial.print("Humidity: "); Serial.println(h);
  delay(2000);
}
