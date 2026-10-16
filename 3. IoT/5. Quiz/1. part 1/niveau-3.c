// led in pin 27

// NIVEAU 3
void setup(){
    pinMode(27, OUTPUT);
}

void loop(){
    // court = S
    for(int i = 0; i < 3; i++){
        digitalWrite(27, HIGH);
        delay(200);
        digitalWrite(27, LOW);
        delay(200);
    }
    // long = O
    for(int i = 0; i < 3; i++){
        digitalWrite(27, HIGH);
        delay(800);
        digitalWrite(27, LOW);
        delay(800);
    }
    // court = S
    for(int i = 0; i < 3; i++){
        digitalWrite(27, HIGH);
        delay(200);
        digitalWrite(27, LOW);
        delay(200);
    }
    delay(1000); // pause
}