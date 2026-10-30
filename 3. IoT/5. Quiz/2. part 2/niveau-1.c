// bouton 4
// led 2
void setup(){
    pinMode(4, INPUT_PULLUP);
    pinMode(2, OUTPUT);
}
void loop() {
    if (digitalRead(4) == LOW) {
    digitalWrite(2, HIGH);
    } else {
    digitalWrite(2, LOW);
    }
}