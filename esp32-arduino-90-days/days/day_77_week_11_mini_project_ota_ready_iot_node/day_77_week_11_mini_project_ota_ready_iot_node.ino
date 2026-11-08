// Day 77: OTA-ready IoT node with MQTT telemetry and NVS boot count.
// Set Wi-Fi credentials and a unique public test topic before use.
#include <WiFi.h>
#include <ArduinoOTA.h>
#include <PubSubClient.h>
#include <Preferences.h>
const char *SSID="YOUR_WIFI_NAME", *PASSWORD="YOUR_WIFI_PASSWORD";
const char *BROKER="test.mosquitto.org";
const char *TOPIC="esp32-learning-demo/your-unique-id/node";
const int SENSOR_PIN=34;
WiFiClient net;
PubSubClient mqtt(net);
Preferences prefs;
unsigned long lastPublish=0;
void connectMqtt(){
  while(!mqtt.connected()){
    String id="ESP32Node-"+String((uint32_t)ESP.getEfuseMac(),HEX);
    if(!mqtt.connect(id.c_str())) delay(3000);
  }
}
void setup(){
  Serial.begin(115200); analogReadResolution(12);
  prefs.begin("iot-node",false);
  uint32_t boots=prefs.getUInt("boots",0)+1;
  prefs.putUInt("boots",boots);
  prefs.end();
  WiFi.begin(SSID,PASSWORD);
  unsigned long start=millis();
  while(WiFi.status()!=WL_CONNECTED && millis()-start<20000) delay(300);
  if(WiFi.status()!=WL_CONNECTED){Serial.println("WiFi failed");return;}
  ArduinoOTA.setHostname("esp32-iot-node");
  ArduinoOTA.begin();
  mqtt.setServer(BROKER,1883);
  Serial.print("Boot count: "); Serial.println(boots);
  Serial.print("IP: "); Serial.println(WiFi.localIP());
}
void loop(){
  ArduinoOTA.handle();
  if(WiFi.status()==WL_CONNECTED){
    if(!mqtt.connected()) connectMqtt();
    mqtt.loop();
    if(millis()-lastPublish>=10000){
      lastPublish=millis();
      String payload="{\"adc\":"+String(analogRead(SENSOR_PIN))+"}";
      mqtt.publish(TOPIC,payload.c_str());
      Serial.println(payload);
    }
  }
}