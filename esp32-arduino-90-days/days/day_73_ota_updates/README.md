# Day 73: OTA firmware updates

**Goal:** Upload new firmware to the ESP32 over Wi-Fi after the first USB upload.

## Before upload
Enter Wi-Fi credentials. Keep them private. Install the ESP32 board package in Arduino IDE.

## First upload
Connect USB and upload this sketch normally. Open Serial Monitor at 115200 baud and note the IP address.

## OTA upload
In Arduino IDE, select the network port named **esp32-learning-board** (it may take a moment to appear), then upload a new sketch over Wi-Fi. Keep the ESP32 powered and on the same network.

## Security
OTA should be protected on trusted networks. This learning example does not configure a password or signed firmware. Do not expose it to untrusted networks.