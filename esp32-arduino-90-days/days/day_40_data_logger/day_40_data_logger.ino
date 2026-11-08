// Day 40: Timestamped analog readings to a microSD card.
// DS3231 I2C: SDA 21, SCL 22. SD SPI: CS 5, SCK 18, MISO 19, MOSI 23.
// Potentiometer wiper -> GPIO 34; outer legs -> 3V3 and GND.
#include <Wire.h>
#include <RTClib.h>
#include <SPI.h>
#include <SD.h>
RTC_DS3231 rtc;
const int SD_CS = 5;
const int SENSOR_PIN = 34;
unsigned long lastLog = 0;
void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22);
  if (!rtc.begin()) { Serial.println("RTC missing"); while (true) delay(1000); }
  if (rtc.lostPower()) rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  SPI.begin(18, 19, 23, SD_CS);
  if (!SD.begin(SD_CS, SPI)) { Serial.println("SD init failed"); while (true) delay(1000); }
  if (!SD.exists("/readings.csv")) {
    File f = SD.open("/readings.csv", FILE_WRITE);
    if (f) { f.println("timestamp,adc_raw"); f.close(); }
  }
}
void loop() {
  if (millis() - lastLog >= 5000) {
    lastLog = millis();
    DateTime t = rtc.now();
    int reading = analogRead(SENSOR_PIN);
    char stamp[24];
    snprintf(stamp, sizeof(stamp), "%04d-%02d-%02d %02d:%02d:%02d",
      t.year(), t.month(), t.day(), t.hour(), t.minute(), t.second());
    File f = SD.open("/readings.csv", FILE_APPEND);
    if (f) {
      f.print(stamp); f.print(","); f.println(reading); f.close();
      Serial.print(stamp); Serial.print(","); Serial.println(reading);
    } else Serial.println("Could not append to CSV");
  }
}