// Day 52: Show live potentiometer readings on an ESP32 web page.
#include <WiFi.h>
#include <WebServer.h>
const char *SSID = "YOUR_WIFI_NAME";
const char *PASSWORD = "YOUR_WIFI_PASSWORD";
const int SENSOR_PIN = 34;
WebServer server(80);
void sendReading() {
  int value = analogRead(SENSOR_PIN);
  server.send(200, "text/plain", String(value));
}
void showDashboard() {
  const char page[] PROGMEM = R"html(
<!doctype html><html><meta name="viewport" content="width=device-width,initial-scale=1">
<h1>ESP32 Live ADC</h1><p>Raw reading: <strong id="value">--</strong></p>
<script>async function update(){try{let r=await fetch('/reading');document.getElementById('value').textContent=await r.text()}catch(e){}}
setInterval(update,1000);update();</script></html>)html";
  server.send(200, "text/html", page);
}
void setup() {
  Serial.begin(115200); analogReadResolution(12);
  WiFi.begin(SSID, PASSWORD);
  unsigned long start=millis();
  while(WiFi.status()!=WL_CONNECTED && millis()-start<20000) delay(300);
  if(WiFi.status()!=WL_CONNECTED){Serial.println("WiFi failed");return;}
  server.on("/", HTTP_GET, showDashboard);
  server.on("/reading", HTTP_GET, sendReading);
  server.begin();
  Serial.print("Open http://"); Serial.println(WiFi.localIP());
}
void loop(){server.handleClient();}