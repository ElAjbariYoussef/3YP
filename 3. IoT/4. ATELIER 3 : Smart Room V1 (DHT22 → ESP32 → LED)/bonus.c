#define LED_PIN 2
const int DOT = 200;

void signal(int duree) {
  digitalWrite(LED_PIN, HIGH); delay(duree);
  digitalWrite(LED_PIN, LOW);  delay(DOT);
}

void setup() { pinMode(LED_PIN, OUTPUT); }

void loop() {
  signal(DOT); signal(DOT);
  delay(2 * DOT);
  signal(3 * DOT); signal(3 * DOT); signal(3 * DOT);
  delay(2 * DOT);
  signal(3 * DOT);
  delay(7 * DOT)
}
