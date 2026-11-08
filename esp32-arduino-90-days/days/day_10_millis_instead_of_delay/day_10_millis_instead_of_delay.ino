// Day 10: Use millis() instead of delay()
// LED: GPIO 18 through a 220-330 ohm resistor to GND.

const int LED_PIN = 18;
const unsigned long BLINK_INTERVAL_MS = 500;
unsigned long previousBlinkTime = 0;
bool ledState = false;

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  previousBlinkTime = millis();
  Serial.println("Day 10 - non-blocking blink");
}

void loop() {
  const unsigned long now = millis();

  if (now - previousBlinkTime >= BLINK_INTERVAL_MS) {
    previousBlinkTime = now;
    ledState = !ledState;
    digitalWrite(LED_PIN, ledState ? HIGH : LOW);
  }

  // Other work can run here while the LED timing continues.
}