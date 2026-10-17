bool etatLed = LOW;
bool dernierEtat = HIGH;

void setup() {
    pinMode(4, INPUT_PULLUP);
    pinMode(2, OUTPUT);
}
void loop() {
    bool etatBouton = digitalRead(4);
    if (dernierEtat == HIGH && etatBouton == LOW) { 
        etatLed = !etatLed;
        digitalWrite(2, etatLed);
    }
    dernierEtat = !dernierEtat;
}