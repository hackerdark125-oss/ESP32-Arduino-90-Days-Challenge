// Day 39: Read date and time from a DS3231 RTC.
#include <Wire.h>
#include <RTClib.h>
RTC_DS3231 rtc;
void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22);
  if (!rtc.begin()) {
    Serial.println("DS3231 not found. Check I2C wiring.");
    while (true) delay(1000);
  }
  if (rtc.lostPower()) {
    Serial.println("RTC lost power; setting time to compile time.");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
}
void loop() {
  DateTime now = rtc.now();
  char buffer[24];
  snprintf(buffer, sizeof(buffer), "%04d-%02d-%02d %02d:%02d:%02d",
           now.year(), now.month(), now.day(),
           now.hour(), now.minute(), now.second());
  Serial.println(buffer);
  delay(1000);
}