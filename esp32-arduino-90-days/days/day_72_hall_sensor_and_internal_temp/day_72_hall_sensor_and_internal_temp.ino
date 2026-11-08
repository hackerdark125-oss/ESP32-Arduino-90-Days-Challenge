// Day 72: Read the original ESP32 Hall sensor and internal temperature estimate.
// This sketch targets classic ESP32-WROOM-32 only.
void setup(){
  Serial.begin(115200);
  Serial.println("Classic ESP32 internal sensor demo");
}
void loop(){
  int hallValue=hallRead();
  float chipTempC=temperatureRead();
  Serial.print("Hall sensor: "); Serial.println(hallValue);
  Serial.print("Internal temperature estimate: ");
  Serial.print(chipTempC); Serial.println(" C");
  delay(1000);
}