const int SEUIL = 1500, LDR = 34, BUZZER = 18, button = 2;
bool arme = LOW;
bool dernierEtat = HIGH;
void setup() {
    pinMode(BUZZER, OUTPUT);
    pinMode(button, INPUT_PULLUP);
    Serial.begin(115200);
}
void loop() {
    bool etat = digitalRead(button);
    int lum = analogRead(LDR);
    Serial.println(lum);
    if (dernierEtat == HIGH && etat == LOW) {
      arme = !arme;
      delay(50);
    }
    dernierEtat = etat;
    if (arme && lum < SEUIL){
        tone(BUZZER, 1000);
    } else {
        noTone(BUZZER);
    }
    delay(100);
}