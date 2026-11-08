// Day 54: WebSocket server broadcasts a potentiometer reading.
// Install the "WebSockets" library by Markus Sattler.
#include <WiFi.h>
#include <WebSocketsServer.h>
const char *SSID = "YOUR_WIFI_NAME";
const char *PASSWORD = "YOUR_WIFI_PASSWORD";
WebSocketsServer webSocket(81);
const int SENSOR_PIN = 34;
unsigned long lastBroadcast = 0;
void onWebSocketEvent(uint8_t client, WStype_t type, uint8_t *payload, size_t length) {
  if (type == WStype_CONNECTED) webSocket.sendTXT(client, "ESP32 WebSocket connected");
}
void setup() {
  Serial.begin(115200);
  analogReadResolution(12);
  WiFi.begin(SSID, PASSWORD);
  unsigned long start=millis();
  while(WiFi.status()!=WL_CONNECTED && millis()-start<20000) delay(300);
  if(WiFi.status()!=WL_CONNECTED){Serial.println("WiFi failed");return;}
  webSocket.begin();
  webSocket.onEvent(onWebSocketEvent);
  Serial.print("WebSocket server: ws://"); Serial.print(WiFi.localIP()); Serial.println(":81/");
}
void loop() {
  webSocket.loop();
  if(millis()-lastBroadcast>=500){
    lastBroadcast=millis();
    String value=String(analogRead(SENSOR_PIN));
    webSocket.broadcastTXT(value);
  }
}