// Day 76: Measure a battery through a resistor divider.
// Example: battery + -> 100k -> GPIO34 -> 100k -> GND; battery - -> GND.
// Never connect a LiPo cell directly to an ESP32 ADC pin.
const int BATTERY_PIN=34;
const float R_TOP=100000.0f;
const float R_BOTTOM=100000.0f;
const float ADC_REFERENCE=3.3f;
void setup(){
  Serial.begin(115200);
  analogReadResolution(12);
}
void loop(){
  int raw=analogRead(BATTERY_PIN);
  float pinVoltage=(raw/4095.0f)*ADC_REFERENCE;
  float batteryVoltage=pinVoltage*(R_TOP+R_BOTTOM)/R_BOTTOM;
  Serial.print("ADC: "); Serial.print(raw);
  Serial.print(" | Estimated battery voltage: ");
  Serial.print(batteryVoltage,2); Serial.println(" V");
  delay(1000);
}