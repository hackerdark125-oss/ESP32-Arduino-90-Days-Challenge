// Day 9: Arrays and loops - Knight Rider LED chase
// ESP32-WROOM-32: five LEDs on GPIO 16, 17, 18, 19 and 21.
// Each LED must have its own 220-330 ohm series resistor.

const int ledPins[] = {16, 17, 18, 19, 21};
const int LED_COUNT = sizeof(ledPins) / sizeof(ledPins[0]);
const int STEP_DELAY_MS = 120;

void turnAllOff() {
  for (int i = 0; i < LED_COUNT; i++) {
    digitalWrite(ledPins[i], LOW);
  }
}

void showLedAt(int index) {
  turnAllOff();
  digitalWrite(ledPins[index], HIGH);
}

void setup() {
  Serial.begin(115200);
  for (int i = 0; i < LED_COUNT; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  turnAllOff();
  Serial.println("Day 9 - Knight Rider LED chase");
}

void loop() {
  // Move from left to right.
  for (int i = 0; i < LED_COUNT; i++) {
    showLedAt(i);
    delay(STEP_DELAY_MS);
  }

  // Move back without repeating the two end LEDs.
  for (int i = LED_COUNT - 2; i > 0; i--) {
    showLedAt(i);
    delay(STEP_DELAY_MS);
  }
}