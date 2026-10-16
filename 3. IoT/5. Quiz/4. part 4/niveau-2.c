const int SEUIL = 1500, LDR = 34, BUZZER = 18, LED = 2;
void setup() {
    pinMode(BUZZER, OUTPUT);
    pinMode(LED, OUTPUT);
    Serial.begin(115200);
}
void loop() {
    int lum = analogRead(LDR);
    Serial.println(lum);
    if (lum < SEUIL) {
        digitalWrite(LED, HIGH);
        tone(BUZZER, 1000);
    } else {
        digitalWrite(LED, LOW);
        noTone(BUZZER);
    }
    delay(100);
    digitalWrite(LED, LOW);
    delay(50);
}