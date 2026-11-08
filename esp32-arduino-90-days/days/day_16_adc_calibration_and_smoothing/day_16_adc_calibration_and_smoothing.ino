// Day 16: Average ADC samples and map the result.
// Potentiometer wiper -> GPIO 34; outer legs -> 3V3 and GND.
const int POT_PIN = 34;
const int SAMPLE_COUNT = 20;
int readSmoothedADC() {
  unsigned long total = 0;
  for (int i = 0; i < SAMPLE_COUNT; i++) {
    total += analogRead(POT_PIN);
    delay(2);
  }
  return total / SAMPLE_COUNT;
}
void setup() {
  Serial.begin(115200);
  analogReadResolution(12);
}
void loop() {
  int smooth = readSmoothedADC();
  int percent = map(smooth, 0, 4095, 0, 100);
  Serial.print("Smoothed ADC: "); Serial.print(smooth);
  Serial.print(" | Position: "); Serial.print(percent);
  Serial.println("%");
  delay(200);
}