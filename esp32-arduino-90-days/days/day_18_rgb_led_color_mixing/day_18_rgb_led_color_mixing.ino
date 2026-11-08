// Day 18: RGB LED color mixing with LEDC (Arduino-ESP32 core 3.x).
// Assumes a common-cathode RGB LED. Each color pin needs its own resistor.
const int RED_PIN = 25;
const int GREEN_PIN = 26;
const int BLUE_PIN = 27;
const int PWM_FREQ = 5000;
const int PWM_BITS = 8;
void setColor(uint8_t red, uint8_t green, uint8_t blue) {
  ledcWrite(RED_PIN, red);
  ledcWrite(GREEN_PIN, green);
  ledcWrite(BLUE_PIN, blue);
}
void setup() {
  Serial.begin(115200);
  bool ok = ledcAttach(RED_PIN, PWM_FREQ, PWM_BITS) &&
            ledcAttach(GREEN_PIN, PWM_FREQ, PWM_BITS) &&
            ledcAttach(BLUE_PIN, PWM_FREQ, PWM_BITS);
  if (!ok) {
    Serial.println("LEDC attach failed.");
    while (true) delay(1000);
  }
}
void loop() {
  setColor(255, 0, 0); delay(1000);     // red
  setColor(0, 255, 0); delay(1000);     // green
  setColor(0, 0, 255); delay(1000);     // blue
  setColor(255, 80, 0); delay(1000);    // orange
  setColor(120, 0, 255); delay(1000);   // purple
  setColor(255, 255, 255); delay(1000); // white
  setColor(0, 0, 0); delay(500);
}