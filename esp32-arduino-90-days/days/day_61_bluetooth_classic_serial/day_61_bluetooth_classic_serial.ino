// Day 61: Bluetooth Classic serial bridge for original ESP32-WROOM-32.
#include "BluetoothSerial.h"
BluetoothSerial SerialBT;
void setup(){
  Serial.begin(115200);
  if(!SerialBT.begin("ESP32-Serial-Demo")){
    Serial.println("Bluetooth start failed.");
    while(true) delay(1000);
  }
  Serial.println("Pair with ESP32-Serial-Demo from your phone.");
}
void loop(){
  while(Serial.available()) SerialBT.write(Serial.read());
  while(SerialBT.available()) Serial.write(SerialBT.read());
}