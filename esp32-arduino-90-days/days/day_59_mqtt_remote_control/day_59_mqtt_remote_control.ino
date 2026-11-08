// Day 59: Control a low-voltage LED from an MQTT message.
#include <WiFi.h>
#include <PubSubClient.h>
const char *SSID="YOUR_WIFI_NAME", *PASSWORD="YOUR_WIFI_PASSWORD";
const char *BROKER="test.mosquitto.org";
const char *TOPIC="esp32-learning-demo/your-unique-id/led";
const int LED_PIN=18;
WiFiClient net;
PubSubClient mqtt(net);
void onMessage(char *topic, byte *payload, unsigned int length){
  String message;
  for(unsigned int i=0;i<length;i++) message+=(char)payload[i];
  message.trim(); message.toUpperCase();
  if(message=="ON") digitalWrite(LED_PIN,HIGH);
  else if(message=="OFF") digitalWrite(LED_PIN,LOW);
  Serial.print("Command: "); Serial.println(message);
}
void connectMqtt(){
  while(!mqtt.connected()){
    String id="ESP32Control-"+String((uint32_t)ESP.getEfuseMac(),HEX);
    if(mqtt.connect(id.c_str())) mqtt.subscribe(TOPIC);
    else delay(3000);
  }
}
void setup(){
  Serial.begin(115200); pinMode(LED_PIN,OUTPUT); digitalWrite(LED_PIN,LOW);
  WiFi.begin(SSID,PASSWORD); while(WiFi.status()!=WL_CONNECTED) delay(300);
  mqtt.setServer(BROKER,1883); mqtt.setCallback(onMessage);
}
void loop(){
  if(!mqtt.connected()) connectMqtt();
  mqtt.loop();
}