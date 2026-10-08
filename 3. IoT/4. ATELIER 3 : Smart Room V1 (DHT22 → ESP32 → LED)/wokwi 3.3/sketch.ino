#include "DHT.h"
#define DHTPIN 4
#define DHTTYPE DHT22
#define LED_PIN 2
#define BUZZER_PIN 5
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  dht.begin();
}

void loop() {
  float t = dht.readTemperature();
  float h = dht.readHumidity();

  if (isnan(t) || isnan(h)) {
    Serial.println("Erreur de lecture DHT22");
    delay(2000);
    return;
  }
  Serial.print("Temperature: "); Serial.print(t); Serial.print(" °C ");
  Serial.print("Humidity: "); Serial.println(h);
  if (t > 25) digitalWrite(LED_PIN, HIGH);
  else        digitalWrite(LED_PIN, LOW);
  if (t > 30) tone(BUZZER_PIN, 1000);
  else        noTone(BUZZER_PIN);

  delay(2000);
}
