// Day 70: Wake, log an ADC sample to NVS, then deep sleep.
#include <Preferences.h>
#include "esp_sleep.h"
Preferences prefs;
const int SENSOR_PIN=34;
void setup(){
  Serial.begin(115200); delay(300);
  prefs.begin("logger",false);
  uint32_t samples=prefs.getUInt("samples",0)+1;
  int reading=analogRead(SENSOR_PIN);
  prefs.putUInt("samples",samples);
  Serial.print("Sample #"); Serial.print(samples);
  Serial.print(" | ADC="); Serial.println(reading);
  prefs.end();
  Serial.println("Sleeping for 15 seconds...");
  Serial.flush();
  esp_sleep_enable_timer_wakeup(15ULL*1000000ULL);
  esp_deep_sleep_start();
}
void loop(){}