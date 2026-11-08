// Day 47: Make a basic HTTP GET request.
#include <WiFi.h>
#include <HTTPClient.h>
const char *WIFI_SSID = "YOUR_WIFI_NAME";
const char *WIFI_PASSWORD = "YOUR_WIFI_PASSWORD";
const char *URL = "http://httpbin.org/get";
void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  unsigned long started = millis();
  while (WiFi.status() != WL_CONNECTED && millis() - started < 20000) delay(300);
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Wi-Fi connection failed.");
    return;
  }
  HTTPClient http;
  http.begin(URL); // Plain HTTP for this introductory demo; do not send secrets.
  int status = http.GET();
  Serial.print("HTTP status: "); Serial.println(status);
  if (status > 0) Serial.println(http.getString());
  else Serial.println(http.errorToString(status));
  http.end();
}
void loop() {}