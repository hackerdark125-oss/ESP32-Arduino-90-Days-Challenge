// Day 20: Simple tones with a passive buzzer (Arduino-ESP32 core 3.x).
// Buzzer + -> GPIO 25; buzzer - -> GND. Use a small piezo/passive buzzer.
const int BUZZER_PIN = 25;
void setup() {
  Serial.begin(115200);
  if (!ledcAttach(BUZZER_PIN, 2000, 8)) {
    Serial.println("LEDC attach failed.");
    while (true) delay(1000);
  }
}
void playTone(int frequency, int durationMs) {
  ledcWriteTone(BUZZER_PIN, frequency);
  delay(durationMs);
  ledcWriteTone(BUZZER_PIN, 0);
  delay(80);
}
void loop() {
  playTone(262, 300); // C4
  playTone(330, 300); // E4
  playTone(392, 300); // G4
  playTone(523, 500); // C5
  delay(1000);
}