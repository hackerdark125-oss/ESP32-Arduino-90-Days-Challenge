// Day 26: External interrupt with a button.
// Button between GPIO 27 and GND; INPUT_PULLUP makes a press LOW.
const int BUTTON_PIN = 27;
const int LED_PIN = 18;
volatile bool buttonEvent = false;
bool ledState = false;
unsigned long lastAcceptedPress = 0;
void IRAM_ATTR onButtonPress() {
  buttonEvent = true; // Keep ISR short; do not print or use delay here.
}
void setup() {
  Serial.begin(115200);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), onButtonPress, FALLING);
  Serial.println("Press the button to toggle the LED.");
}
void loop() {
  if (buttonEvent) {
    noInterrupts();
    buttonEvent = false;
    interrupts();

    unsigned long now = millis();
    if (now - lastAcceptedPress >= 200) {
      lastAcceptedPress = now;
      ledState = !ledState;
      digitalWrite(LED_PIN, ledState ? HIGH : LOW);
      Serial.println(ledState ? "LED ON" : "LED OFF");
    }
  }
}