// Day 50: Serve a simple web page from the ESP32.
#include <WiFi.h>
#include <WebServer.h>
const char *SSID = "YOUR_WIFI_NAME";
const char *PASSWORD = "YOUR_WIFI_PASSWORD";
WebServer server(80);
void handleRoot() {
  server.send(200, "text/html",
    "<!doctype html><html><head><meta name='viewport' content='width=device-width,initial-scale=1'>"
    "<title>ESP32</title></head><body><h1>Hello from ESP32</h1>"
    "<p>Your ESP32 web server is running.</p></body></html>");
}
void setup() {
  Serial.begin(115200);
  WiFi.begin(SSID, PASSWORD);
  unsigned long start = millis();
  while (WiFi.status() != WL_CONNECTED && millis() - start < 20000) delay(300);
  if (WiFi.status() != WL_CONNECTED) { Serial.println("WiFi failed"); return; }
  server.on("/", HTTP_GET, handleRoot);
  server.begin();
  Serial.print("Open http://"); Serial.println(WiFi.localIP());
}
void loop() {
  server.handleClient();
}