// Day 63: BLE sensor beacon - expose potentiometer value as a readable/notifiable characteristic.
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>
#define SERVICE_UUID "a1b2c3d4-1111-2222-3333-1234567890ab"
#define SENSOR_UUID  "a1b2c3d4-1111-2222-3333-1234567890ac"
BLECharacteristic *sensorCharacteristic;
const int SENSOR_PIN=34;
bool deviceConnected=false;
class ServerCallbacks : public BLEServerCallbacks {
  void onConnect(BLEServer *server) override { deviceConnected=true; }
  void onDisconnect(BLEServer *server) override {
    deviceConnected=false;
    BLEDevice::startAdvertising();
  }
};
void setup(){
  Serial.begin(115200); analogReadResolution(12);
  BLEDevice::init("ESP32-Sensor-Beacon");
  BLEServer *server=BLEDevice::createServer();
  server->setCallbacks(new ServerCallbacks());
  BLEService *service=server->createService(SERVICE_UUID);
  sensorCharacteristic=service->createCharacteristic(
    SENSOR_UUID, BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_NOTIFY);
  sensorCharacteristic->addDescriptor(new BLE2902());
  sensorCharacteristic->setValue("0");
  service->start();
  BLEAdvertising *adv=BLEDevice::getAdvertising();
  adv->addServiceUUID(SERVICE_UUID); adv->start();
  Serial.println("BLE sensor beacon ready.");
}
void loop(){
  static unsigned long last=0;
  if(millis()-last>=1000){
    last=millis();
    String value=String(analogRead(SENSOR_PIN));
    sensorCharacteristic->setValue(value.c_str());
    if(deviceConnected) sensorCharacteristic->notify();
    Serial.println(value);
  }
}