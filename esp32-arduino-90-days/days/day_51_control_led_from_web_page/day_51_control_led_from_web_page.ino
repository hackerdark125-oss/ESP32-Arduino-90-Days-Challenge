// Day 51: Control an LED from a local ESP32 web page.
// LED GPIO 18 -> 220-330 ohm resistor -> LED anode; cathode -> GND.
#include <WiFi.h>
#include <WebServer.h>
const char *SSID = "YOUR_WIFI_NAME";
const char *PASSWORD = "YOUR_WIFI_PASSWORD";
const int LED_PIN = 18;
WebServer server(80);
void showPage() {
  String html = "<!doctype html><html><meta name='viewport' content='width=device-width,initial-scale=1'>"
    "<h1>ESP32 LED Control</h1><p>LED is ";
  html += digitalRead(LED_PIN) ? "ON" : "OFF";
  html += "</p><a href='/on'><button>Turn ON</button></a> "
          "<a href='/off'><button>Turn OFF</button></a></html>";
  server.send(200, "text/html", html);
}
void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT); digitalWrite(LED_PIN, LOW);
  WiFi.begin(SSID, PASSWORD);
  unsigned long start = millis();
  while (WiFi.status() != WL_CONNECTED && millis() - start < 20000) delay(300);
  if (WiFi.status() != WL_CONNECTED) { Serial.println("WiFi failed"); return; }
  server.on("/", HTTP_GET, showPage);
  server.on("/on", HTTP_GET, [](){ digitalWrite(LED_PIN, HIGH); showPage(); });
  server.on("/off", HTTP_GET, [](){ digitalWrite(LED_PIN, LOW); showPage(); });
  server.begin();
  Serial.print("Open http://"); Serial.println(WiFi.localIP());
}
void loop() { server.handleClient(); }