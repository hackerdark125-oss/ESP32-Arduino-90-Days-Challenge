// Day 55: Store and read a text file in ESP32 LittleFS.
#include <LittleFS.h>
void setup() {
  Serial.begin(115200);
  if (!LittleFS.begin(true)) {
    Serial.println("LittleFS mount failed.");
    return;
  }
  File file = LittleFS.open("/notes.txt", FILE_WRITE);
  if (!file) { Serial.println("Open for write failed."); return; }
  file.println("Hello from ESP32 flash storage.");
  file.close();
  file = LittleFS.open("/notes.txt", FILE_READ);
  if (!file) { Serial.println("Open for read failed."); return; }
  Serial.println("File contents:");
  while (file.available()) Serial.write(file.read());
  file.close();
}
void loop() {}