// bouton 4
// led 2
// led2 5
void setup(){
    Serial.begin(115200);
    pinMode(4, INPUT_PULLUP);
    pinMode(2, OUTPUT);
    pinMode(5, OUTPUT);
}
void loop() {
    if (digitalRead(4) == LOW) {
        digitalWrite(2, LOW);
        digitalWrite(5, HIGH);
        Serial.println("LED 1 : Eteint , LED 2 : Allumé");
    } else {
        digitalWrite(2, HIGH);
        digitalWrite(5, LOW);

        Serial.println("LED 1 : Allumé , LED 2 : Eteint");
    }
}