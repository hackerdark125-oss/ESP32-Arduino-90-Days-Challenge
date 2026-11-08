// Day 22: Read an LDR using a voltage divider.
// Wiring: 3V3 -> LDR -> GPIO 34 -> 10k resistor -> GND.
const int LDR_PIN = 34;
void setup() {
  Serial.begin(115200);
  analogReadResolution(12);
}
void loop() {
  int lightLevel = analogRead(LDR_PIN);
  Serial.print("LDR ADC: ");
  Serial.print(lightLevel);
  Serial.print(" | ");
  Serial.println(lightLevel > 2000 ? "Brighter side of divider range" : "Darker side of divider range");
  delay(500);
}