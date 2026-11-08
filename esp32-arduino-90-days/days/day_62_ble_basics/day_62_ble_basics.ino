// Day 62: BLE GATT service with a writable characteristic.
// Use a BLE scanner/terminal app to discover the service and write text.
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>
#define SERVICE_UUID        "6e400001-b5a3-f393-e0a9-e50e24dcca9e"
#define CHARACTERISTIC_UUID "6e400002-b5a3-f393-e0a9-e50e24dcca9e"
class WriteCallbacks : public BLECharacteristicCallbacks {
  void onWrite(BLECharacteristic *characteristic) override {
    String value = characteristic->getValue().c_str();
    Serial.print("BLE received: "); Serial.println(value);
  }
};
void setup(){
  Serial.begin(115200);
  BLEDevice::init("ESP32-BLE-Lesson");
  BLEServer *server=BLEDevice::createServer();
  BLEService *service=server->createService(SERVICE_UUID);
  BLECharacteristic *characteristic=service->createCharacteristic(
    CHARACTERISTIC_UUID, BLECharacteristic::PROPERTY_READ |
    BLECharacteristic::PROPERTY_WRITE);
  characteristic->setValue("Send a message");
  characteristic->setCallbacks(new WriteCallbacks());
  service->start();
  BLEAdvertising *advertising=BLEDevice::getAdvertising();
  advertising->addServiceUUID(SERVICE_UUID);
  advertising->start();
  Serial.println("BLE advertising as ESP32-BLE-Lesson");
}
void loop(){delay(1000);}