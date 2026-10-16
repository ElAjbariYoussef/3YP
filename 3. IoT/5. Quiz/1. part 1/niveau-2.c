// led in pin 27

// niveau 2

void setup(){
    pinMode(27, OUTPUT);
}

void loop(){
    digitalWrite(27, HIGH);
    delay(200);
    digitalWrite(27, LOW);
    delay(800);
}
