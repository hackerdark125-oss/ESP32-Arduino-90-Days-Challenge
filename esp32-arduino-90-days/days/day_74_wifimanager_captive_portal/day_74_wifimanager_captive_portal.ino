// Day 74: Configure Wi-Fi credentials through a WiFiManager portal.
#include <WiFi.h>
#include <WiFiManager.h>
WiFiManager wifiManager;
void setup(){
  Serial.begin(115200);
  wifiManager.setConfigPortalTimeout(180);
  bool connected=wifiManager.autoConnect("ESP32-Setup-Portal");
  if(!connected){
    Serial.println("Portal timed out; restarting.");
    ESP.restart();
  }
  Serial.print("Connected. IP: "); Serial.println(WiFi.localIP());
}
void loop(){
  if(WiFi.status()!=WL_CONNECTED){
    Serial.println("WiFi lost; reopening setup portal.");
    wifiManager.startConfigPortal("ESP32-Setup-Portal");
  }
  delay(1000);
}