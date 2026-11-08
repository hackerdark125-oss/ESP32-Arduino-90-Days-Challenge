// Day 38: Write to and read from a microSD card over SPI.
#include <SPI.h>
#include <SD.h>
const int SD_CS = 5;
void setup() {
  Serial.begin(115200);
  SPI.begin(18, 19, 23, SD_CS); // SCK, MISO, MOSI, CS
  if (!SD.begin(SD_CS, SPI)) {
    Serial.println("SD init failed. Check card, wiring and format.");
    return;
  }
  File file = SD.open("/esp32-log.txt", FILE_APPEND);
  if (!file) {
    Serial.println("Could not open file for writing.");
    return;
  }
  file.println("Hello from ESP32 SD card");
  file.close();
  Serial.println("Wrote a line. Reading file:");
  file = SD.open("/esp32-log.txt", FILE_READ);
  if (!file) return;
  while (file.available()) Serial.write(file.read());
  file.close();
}
void loop() {}