// Day 6: Button debounce on ESP32
// Button: GPIO 19 to GND. LED: GPIO 18 through a 220-330 ohm resistor to GND.

const int BUTTON_PIN = 19;
const int LED_PIN = 18;
const unsigned long DEBOUNCE_MS = 50;

bool ledState = false;
int stableButtonState = HIGH;
int lastReading = HIGH;
unsigned long lastChangeTime = 0;

void setup() {
  Serial.begin(115200);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  Serial.println("Day 6 - debounced button");
}

void loop() {
  const int reading = digitalRead(BUTTON_PIN);

  if (reading != lastReading) {
    lastChangeTime = millis();
  }

  if (millis() - lastChangeTime >= DEBOUNCE_MS) {
    if (reading != stableButtonState) {
      stableButtonState = reading;
      if (stableButtonState == LOW) {
        ledState = !ledState;
        digitalWrite(LED_PIN, ledState ? HIGH : LOW);
        Serial.println(ledState ? "LED ON" : "LED OFF");
      }
    }
  }
  lastReading = reading;
}