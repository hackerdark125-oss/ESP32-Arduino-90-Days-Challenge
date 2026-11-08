# Day 62: BLE basics

**Goal:** Create a Bluetooth Low Energy GATT service with a readable/writable characteristic.

## Run
Upload and open Serial Monitor at 115200 baud. Use a BLE scanner app on your phone to find **ESP32-BLE-Lesson**, connect, open the advertised service and write a short text value to the characteristic.

## Concepts
GATT organizes BLE data into services and characteristics. A characteristic can expose properties such as READ, WRITE and NOTIFY.

## Compatibility
This example targets Arduino-ESP32 with the bundled BLE library. If your installed core has a different BLE API, install/use a matching ESP32 BLE library version.