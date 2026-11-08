// Day 71: Capacitive touch input on classic ESP32-WROOM-32.
// GPIO 4 is touch channel T0 on the original ESP32.
const int TOUCH_PIN=4;
uint16_t baseline=0;
void setup(){
  Serial.begin(115200);
  delay(500);
  baseline=touchRead(TOUCH_PIN);
  Serial.print("Baseline touch value: "); Serial.println(baseline);
}
void loop(){
  uint16_t value=touchRead(TOUCH_PIN);
  bool touched=value < (baseline*7/10);
  Serial.print("Touch: "); Serial.print(value);
  Serial.println(touched ? "  DETECTED" : "  idle");
  delay(150);
}