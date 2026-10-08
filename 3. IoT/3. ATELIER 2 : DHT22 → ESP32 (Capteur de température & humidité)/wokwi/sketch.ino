#define LDR_PIN 34
#define LAMP_PIN 2
const int SEUIL = 2000;$

void setup() {
  Serial.begin(115200);
  pinMode(LAMP_PIN, OUTPUT);
}

void loop() {
  int lum = analogRead(LDR_PIN); $$
  Serial.print("Luminosite (ADC): "); Serial.println(lum);

  if (lum < SEUIL) digitalWrite(LAMP_PIN, HIGH);
  else             digitalWrite(LAMP_PIN, LOW);

  delay(500);
}