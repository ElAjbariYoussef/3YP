const int POT = 34;
void setup() {
    Serial.begin(115200);
}
void loop() {
    int valeur = analogRead(POT);
    Serial.print("Valeur : ");
    Serial.print(map(valeur,0,4095,0,100));
    Serial.println("%");
    delay(200);
}