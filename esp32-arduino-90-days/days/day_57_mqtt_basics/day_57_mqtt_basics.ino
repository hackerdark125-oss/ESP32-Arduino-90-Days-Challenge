// Day 57: MQTT publish/subscribe basics using a public test broker.
// Do not publish private data or use this broker for production.
#include <WiFi.h>
#include <PubSubClient.h>
const char *SSID = "YOUR_WIFI_NAME";
const char *PASSWORD = "YOUR_WIFI_PASSWORD";
const char *BROKER = "test.mosquitto.org";
WiFiClient wifiClient;
PubSubClient mqtt(wifiClient);
const char *TOPIC = "esp32-learning-demo/your-unique-id";
void callback(char *topic, byte *payload, unsigned int length) {
  Serial.print("Message on "); Serial.print(topic); Serial.print(": ");
  for (unsigned int i=0; i<length; i++) Serial.print((char)payload[i]);
  Serial.println();
}
void reconnect() {
  while (!mqtt.connected()) {
    String clientId = "ESP32Demo-" + String((uint32_t)ESP.getEfuseMac(), HEX);
    if (mqtt.connect(clientId.c_str())) mqtt.subscribe(TOPIC);
    else delay(3000);
  }
}
void setup() {
  Serial.begin(115200);
  WiFi.begin(SSID, PASSWORD);
  while(WiFi.status()!=WL_CONNECTED) delay(300);
  mqtt.setServer(BROKER, 1883);
  mqtt.setCallback(callback);
}
void loop() {
  if (!mqtt.connected()) reconnect();
  mqtt.loop();
  static unsigned long last=0;
  if(millis()-last>=5000){
    last=millis();
    mqtt.publish(TOPIC, "Hello from ESP32");
  }
}