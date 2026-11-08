// Day 46: Synchronize system time from NTP after Wi-Fi connects.
#include <WiFi.h>
#include <time.h>
const char *WIFI_SSID = "YOUR_WIFI_NAME";
const char *WIFI_PASSWORD = "YOUR_WIFI_PASSWORD";
const char *NTP_SERVER = "pool.ntp.org";
const long GMT_OFFSET_SEC = 19800; // India Standard Time UTC+5:30
const int DAYLIGHT_OFFSET_SEC = 0;
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
  configTime(GMT_OFFSET_SEC, DAYLIGHT_OFFSET_SEC, NTP_SERVER);
  Serial.println("Waiting for NTP time...");
  struct tm timeInfo;
  if (getLocalTime(&timeInfo, 15000)) {
    Serial.println(&timeInfo, "%Y-%m-%d %H:%M:%S");
  } else Serial.println("NTP time sync timed out.");
}
void loop() {
  struct tm timeInfo;
  if (getLocalTime(&timeInfo, 1000)) Serial.println(&timeInfo, "%H:%M:%S");
  delay(5000);
}