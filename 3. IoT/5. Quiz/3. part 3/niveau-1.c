const int POT = 34;
void setup() {
    Serial.begin(115200);
}
void loop() {
    int valeur = analogRead(POT);
    Serial.println(valeur);
    delay(200);
}