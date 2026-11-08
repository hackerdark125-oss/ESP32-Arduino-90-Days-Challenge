// Day 45: Make the ESP32 its own Wi-Fi access point.
#include <WiFi.h>
const char *AP_SSID = "ESP32-Learning-AP";
const char *AP_PASSWORD = "esp32demo"; // 8+ characters; change for your own use.
void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_AP);
  bool started = WiFi.softAP(AP_SSID, AP_PASSWORD);
  if (!started) {
    Serial.println("Access point start failed.");
    return;
  }
  Serial.print("AP SSID: "); Serial.println(AP_SSID);
  Serial.print("AP IP: "); Serial.println(WiFi.softAPIP());
}
void loop() {
  delay(5000);
  Serial.print("Connected stations: ");
  Serial.println(WiFi.softAPgetStationNum());
}