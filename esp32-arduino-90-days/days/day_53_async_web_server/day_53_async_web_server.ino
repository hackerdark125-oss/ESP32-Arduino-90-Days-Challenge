// Day 53: Minimal ESPAsyncWebServer example.
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
const char *SSID = "YOUR_WIFI_NAME";
const char *PASSWORD = "YOUR_WIFI_PASSWORD";
AsyncWebServer server(80);
void setup() {
  Serial.begin(115200);
  WiFi.begin(SSID, PASSWORD);
  unsigned long start=millis();
  while(WiFi.status()!=WL_CONNECTED && millis()-start<20000) delay(300);
  if(WiFi.status()!=WL_CONNECTED){Serial.println("WiFi failed");return;}
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(200, "text/html",
      "<!doctype html><html><h1>Async ESP32 Server</h1><p>Request handled asynchronously.</p></html>");
  });
  server.on("/status", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(200, "text/plain", "ESP32 online");
  });
  server.begin();
  Serial.print("Open http://"); Serial.println(WiFi.localIP());
}
void loop() {
  // AsyncWebServer handles requests in the background.
}