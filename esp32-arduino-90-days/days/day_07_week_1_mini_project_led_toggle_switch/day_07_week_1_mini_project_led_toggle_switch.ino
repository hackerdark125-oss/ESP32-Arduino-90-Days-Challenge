// Day 7: Week 1 mini project - LED toggle switch
// One stable button press changes the LED state.
// Board: ESP32-WROOM-32 (3.3 V GPIO)

const int BUTTON_PIN = 18;  // Push button connects this pin to GND
const int LED_PIN = 23;     // External LED through a 220 ohm resistor

const unsigned long DEBOUNCE_MS = 50;

bool ledState = false;
int lastRawReading = HIGH;
int stableButtonState = HIGH;
unsigned long lastChangeTime = 0;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);

  digitalWrite(LED_PIN, LOW);
  Serial.begin(115200);
  Serial.println("Day 7: LED toggle switch ready");
}

void loop() {
  const int rawReading = digitalRead(BUTTON_PIN);

  // Restart the debounce timer whenever the raw input changes.
  if (rawReading != lastRawReading) {
    lastChangeTime = millis();
    lastRawReading = rawReading;
  }

  // Accept the new reading only after it stays stable.
  if ((millis() - lastChangeTime) >= DEBOUNCE_MS) {
    if (rawReading != stableButtonState) {
      stableButtonState = rawReading;

      // INPUT_PULLUP means a pressed button reads LOW.
      if (stableButtonState == LOW) {
        ledState = !ledState;
        digitalWrite(LED_PIN, ledState ? HIGH : LOW);

        Serial.print("LED: ");
        Serial.println(ledState ? "ON" : "OFF");
      }
    }
  }
}
