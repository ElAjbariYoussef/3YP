// bouton 4
// led 2
void setup(){
    pinMode(4, INPUT_PULLUP);
    pinMode(2, OUTPUT);
}
void loop() {
    if (digitalRead(BOUTON) == LOW) {
    digitalWrite(LED, HIGH);
    } else {
    digitalWrite(LED, LOW);
    }
}