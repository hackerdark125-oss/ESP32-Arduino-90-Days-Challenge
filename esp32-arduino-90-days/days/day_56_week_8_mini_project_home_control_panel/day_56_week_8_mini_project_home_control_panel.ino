// Day 56: Local low-voltage home control panel.
// Use LEDs or low-voltage modules only. Do not connect mains appliances.
#include <WiFi.h>
#include <WebServer.h>
const char *SSID = "YOUR_WIFI_NAME";
const char *PASSWORD = "YOUR_WIFI_PASSWORD";
const int OUT1 = 18, OUT2 = 19, SENSOR_PIN = 34;
WebServer server(80);
String page() {
  String html = "<!doctype html><html><meta name='viewport' content='width=device-width,initial-scale=1'>"
    "<h1>ESP32 Control Panel</h1><p>Output 1: ";
  html += digitalRead(OUT1) ? "ON" : "OFF";
  html += "</p><a href='/one/on'>ON</a> | <a href='/one/off'>OFF</a><p>Output 2: ";
  html += digitalRead(OUT2) ? "ON" : "OFF";
  html += "</p><a href='/two/on'>ON</a> | <a href='/two/off'>OFF</a><p>ADC: ";
  html += String(analogRead(SENSOR_PIN)) + "</p></html>";
  return html;
}
void setup() {
  Serial.begin(115200);
  pinMode(OUT1, OUTPUT); pinMode(OUT2, OUTPUT);
  digitalWrite(OUT1, LOW); digitalWrite(OUT2, LOW);
  WiFi.begin(SSID, PASSWORD);
  unsigned long start=millis();
  while(WiFi.status()!=WL_CONNECTED && millis()-start<20000) delay(300);
  if(WiFi.status()!=WL_CONNECTED){Serial.println("WiFi failed");return;}
  server.on("/", [](){server.send(200,"text/html",page());});
  server.on("/one/on", [](){digitalWrite(OUT1,HIGH);server.send(200,"text/html",page());});
  server.on("/one/off", [](){digitalWrite(OUT1,LOW);server.send(200,"text/html",page());});
  server.on("/two/on", [](){digitalWrite(OUT2,HIGH);server.send(200,"text/html",page());});
  server.on("/two/off", [](){digitalWrite(OUT2,LOW);server.send(200,"text/html",page());});
  server.begin();
  Serial.print("Open http://"); Serial.println(WiFi.localIP());
}
void loop(){server.handleClient();}