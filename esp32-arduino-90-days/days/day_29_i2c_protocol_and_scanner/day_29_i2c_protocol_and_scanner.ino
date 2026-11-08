// Day 29: I2C scanner for ESP32-WROOM-32.
// Default I2C pins on many ESP32 dev boards: SDA GPIO 21, SCL GPIO 22.
#include <Wire.h>
const int SDA_PIN = 21;
const int SCL_PIN = 22;
void setup() {
  Serial.begin(115200);
  Wire.begin(SDA_PIN, SCL_PIN);
  Serial.println("I2C scanner ready");
}
void loop() {
  int found = 0;
  for (uint8_t address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    uint8_t error = Wire.endTransmission();
    if (error == 0) {
      Serial.print("Found I2C device at 0x");
      if (address < 16) Serial.print("0");
      Serial.println(address, HEX);
      found++;
    }
  }
  if (found == 0) Serial.println("No I2C devices found.");
  else { Serial.print("Devices found: "); Serial.println(found); }
  delay(3000);
}