// Day 73: Upload firmware over Wi-Fi using ArduinoOTA.
#include <WiFi.h>
#include <ArduinoOTA.h>
const char *SSID="YOUR_WIFI_NAME";
const char *PASSWORD="YOUR_WIFI_PASSWORD";
void setup(){
  Serial.begin(115200);
  WiFi.begin(SSID,PASSWORD);
  unsigned long start=millis();
  while(WiFi.status()!=WL_CONNECTED && millis()-start<20000) delay(300);
  if(WiFi.status()!=WL_CONNECTED){Serial.println("WiFi failed");return;}
  ArduinoOTA.setHostname("esp32-learning-board");
  ArduinoOTA
    .onStart([](){Serial.println("OTA update starting");})
    .onEnd([](){Serial.println("\nOTA update finished");})
    .onError([](ota_error_t error){Serial.printf("OTA error[%u]\n",error);});
  ArduinoOTA.begin();
  Serial.print("OTA ready at "); Serial.println(WiFi.localIP());
}
void loop(){
  ArduinoOTA.handle();
}