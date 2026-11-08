// Day 58: Publish a potentiometer reading over MQTT.
#include <WiFi.h>
#include <PubSubClient.h>
const char *SSID="YOUR_WIFI_NAME", *PASSWORD="YOUR_WIFI_PASSWORD";
const char *BROKER="test.mosquitto.org";
const char *TOPIC="esp32-learning-demo/your-unique-id/sensor";
WiFiClient net;
PubSubClient mqtt(net);
const int SENSOR_PIN=34;
void connectMqtt(){
  while(!mqtt.connected()){
    String id="ESP32Sensor-"+String((uint32_t)ESP.getEfuseMac(),HEX);
    if(!mqtt.connect(id.c_str())) delay(3000);
  }
}
void setup(){
  Serial.begin(115200); analogReadResolution(12);
  WiFi.begin(SSID,PASSWORD);
  while(WiFi.status()!=WL_CONNECTED) delay(300);
  mqtt.setServer(BROKER,1883);
}
void loop(){
  if(!mqtt.connected()) connectMqtt();
  mqtt.loop();
  static unsigned long last=0;
  if(millis()-last>=5000){
    last=millis();
    String payload=String(analogRead(SENSOR_PIN));
    mqtt.publish(TOPIC,payload.c_str());
    Serial.print("Published: "); Serial.println(payload);
  }
}