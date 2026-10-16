int i = 0;
void setup() {
    pinMode(4, INPUT_PULLUP); // bouton
    pinMode(2, OUTPUT); // led
}
void loop() {
    i = random(1000, 5000);
    delay(i);
    
    // get time, interrupt delay
}