// Day 15: Read a potentiometer with the ESP32 ADC.
// Potentiometer: outer legs to 3V3 and GND; middle wiper to GPIO 34.
const int POT_PIN = 34; // ADC1 input-only pin
void setup() {
  Serial.begin(115200);
  analogReadResolution(12); // raw range: 0-4095
}
void loop() {
  int raw = analogRead(POT_PIN);
  float voltage = (raw / 4095.0f) * 3.3f; // approximate, not calibrated
  Serial.print("Raw ADC: "); Serial.print(raw);
  Serial.print(" | Approx voltage: "); Serial.print(voltage, 2);
  Serial.println(" V");
  delay(300);
}