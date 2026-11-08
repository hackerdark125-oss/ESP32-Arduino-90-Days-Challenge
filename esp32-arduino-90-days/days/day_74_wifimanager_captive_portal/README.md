# Day 74: WiFiManager captive portal

**Goal:** Configure Wi-Fi without hardcoding the network name and password in the sketch.

## Library
Install **WiFiManager** by tzapu from Arduino IDE Library Manager. Ensure the version is compatible with your ESP32 Arduino core.

## Run
Upload over USB. If no saved network is available, connect a phone to the temporary **ESP32-Setup-Portal** network and follow the captive portal page to select your Wi-Fi network. The ESP32 then prints its IP address.

## Notes
The setup portal is temporary and should not be left open unnecessarily. For production devices, add secure provisioning, credential storage and a recovery process.