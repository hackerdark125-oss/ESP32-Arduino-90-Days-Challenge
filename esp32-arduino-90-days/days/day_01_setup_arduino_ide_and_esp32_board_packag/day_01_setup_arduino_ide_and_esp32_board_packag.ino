// Day 1: Verify Arduino IDE and ESP32 serial upload.
void setup(){
  Serial.begin(115200);
  delay(500);
  Serial.println();
  Serial.println("ESP32 setup successful!");
  Serial.print("Chip model: "); Serial.println(ESP.getChipModel());
  Serial.print("CPU frequency: "); Serial.print(ESP.getCpuFreqMHz()); Serial.println(" MHz");
}
void loop(){
  static unsigned long count=0;
  Serial.print("Running... "); Serial.println(count++);
  delay(2000);
}