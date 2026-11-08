// Day 68: Save a counter in non-volatile Preferences storage.
#include <Preferences.h>
Preferences preferences;
void setup(){
  Serial.begin(115200);
  preferences.begin("esp32-demo",false);
  uint32_t count=preferences.getUInt("boots",0);
  count++;
  preferences.putUInt("boots",count);
  Serial.print("Boot count saved in NVS: ");
  Serial.println(count);
  preferences.end();
}
void loop(){}