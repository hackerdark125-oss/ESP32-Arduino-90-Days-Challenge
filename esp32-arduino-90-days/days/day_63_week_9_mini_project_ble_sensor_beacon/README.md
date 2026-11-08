# Day 63: BLE sensor beacon mini project

**Goal:** Expose a live potentiometer reading over BLE so a phone can read or subscribe to updates.

## Wiring
Potentiometer outer legs → 3V3 and GND; wiper → GPIO 34.

## Run
Upload and open Serial Monitor at 115200 baud. Scan for **ESP32-Sensor-Beacon** using a BLE app. Connect, open the custom service and read/subscribe to the sensor characteristic. A new ADC value is prepared every second.

## Concepts
The sensor characteristic supports READ and NOTIFY. Notifications are sent while a phone is connected. This is a basic GATT sensor example; production BLE devices should define permissions, security and a stable data format.