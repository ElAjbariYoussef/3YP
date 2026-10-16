const int PHOTO = 34;
const int LED = 5;
void setup() {
    Serial.begin(115200);
    pinMode(LED, OUTPUT);
}
void loop() {
    int valeur = analogRead(PHOTO);
    int brightness = map(valeur,0,4095,255,0);
    if (brightness > 100) brightness = 255; // seuil
    analogWrite(LED, brightness);
    delay(10);
}