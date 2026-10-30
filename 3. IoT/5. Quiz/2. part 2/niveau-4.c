int i;
void setup(){
  pinMode(4, INPUT_PULLUP);
  pinMode(2, OUTPUT);
  Serial.begin(115200);

}

void loop() {
    i = random(1000, 5000);
    unsigned long start = millis();
    while (millis() - start < i) {
        if (digitalRead(4) == LOW) { 
            Serial.println("triché");
            while (digitalRead(4) == LOW);
            return;
        }
    }
    digitalWrite(2, HIGH);
    unsigned long t = micros();
    while (digitalRead(4) == HIGH);
    Serial.println((micros() - t) / 1000.0);
    digitalWrite(2, LOW);
    delay(1000);
}