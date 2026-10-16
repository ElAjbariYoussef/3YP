
// niveau 4

void setup(){
    pinMode(27, OUTPUT); // vert
    pinMode(26, OUTPUT); // red
    pinMode(25, OUTPUT); // orange
    pinMode(34, OUTPUT); // p_vert bonus
    pinMode(23, OUTPUT); // p_rouge bonus
}

void loop(){
    digitalWrite(27, HIGH);
    digitalWrite(23, HIGH);
    delay(5000);
    digitalWrite(27, LOW);
    digitalWrite(23, LOW);
    digitalWrite(25, HIGH);
    delay(1000);
    digitalWrite(25, LOW);
    digitalWrite(23,HIGH);
    digitalWrite(34,HIGH);
    delay(5000);
    digitalWrite(23,LOW);
    digitalWrite(34,LOW);
}