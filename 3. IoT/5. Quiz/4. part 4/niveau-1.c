const int LDR = 34, BUZZER = 18, LED = 2;
const int SEUIL = 1500;
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
        digitalWrite(BUZZER, HIGH);
    } else {
        digitalWrite(LED, LOW);
        digitalWrite(BUZZER, LOW);
    }
    delay(100);
}