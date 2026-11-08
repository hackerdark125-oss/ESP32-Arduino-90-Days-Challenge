// Day 17: LED brightness with ESP32 LEDC PWM (Arduino-ESP32 core 3.x).
// LED anode through 220-330 ohm resistor to GPIO 18; cathode to GND.
const int LED_PIN = 18;
const int PWM_FREQUENCY = 5000;
const int PWM_RESOLUTION = 8; // duty: 0-255
void setup() {
  Serial.begin(115200);
  if (!ledcAttach(LED_PIN, PWM_FREQUENCY, PWM_RESOLUTION)) {
    Serial.println("LEDC attach failed - check board/core version.");
    while (true) delay(1000);
  }
}
void loop() {
  for (int duty = 0; duty <= 255; duty += 5) {
    ledcWrite(LED_PIN, duty);
    delay(20);
  }
  for (int duty = 255; duty >= 0; duty -= 5) {
    ledcWrite(LED_PIN, duty);
    delay(20);
  }
}