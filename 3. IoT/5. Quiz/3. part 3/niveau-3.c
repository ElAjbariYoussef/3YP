const int POT = 34;
const int LED = 5;

void setup() {
    Serial.begin(115200);
    pinMode(POT, INPUT);
    ledcAttach(LED, 5000, 8);
}

void loop() {
    int valeur = analogRead(POT);
    int luminosite = map(valeur, 0, 4095, 0, 255);
    ledcWrite(LED, luminosite);
    Serial.println(valeur);
    delay(10);
}