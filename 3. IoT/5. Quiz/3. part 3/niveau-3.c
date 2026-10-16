const int POT = 34;
const int LED = 5;
void setup() {
    Serial.begin(115200);
    pinMode(LED, OUTPUT);
}
void loop() {
    int valeur = analogRead(POT);
    analogWrite(LED, map(valeur,0,4095,0,255));
    delay(10);
}