# Day 61: Bluetooth Classic serial

**Goal:** Exchange text between the ESP32 and a phone over Bluetooth Classic SPP.

## Compatibility
This lesson is for the original **ESP32-WROOM-32**. Some newer ESP32 variants (such as ESP32-S3/C3) do not support Bluetooth Classic SPP.

## Run
Upload the sketch. Pair your phone with **ESP32-Serial-Demo**, then use a Bluetooth serial terminal app. Text sent from the phone appears in USB Serial Monitor; text sent from Serial Monitor is forwarded to the phone.

## Concepts
Bluetooth Classic SPP provides a wireless serial-like connection. Pairing and app behavior vary by phone operating system.