# Day 77: OTA-ready IoT node mini project

**Goal:** Combine Wi-Fi, OTA firmware updates, MQTT telemetry and persistent NVS settings.

## Wiring
Potentiometer outer legs → 3V3 and GND; wiper → GPIO 34.

## Setup
Install PubSubClient. Enter Wi-Fi credentials and choose a unique MQTT topic. Do not commit real credentials or publish private data.

## Run
Upload first over USB. Open Serial Monitor at 115200 baud and note the IP address. The node stores a boot count in NVS, starts ArduinoOTA and publishes an ADC JSON value every 10 seconds to the public test broker.

## Security and reliability
The example uses unencrypted public MQTT and OTA without a password, for a controlled learning network only. Production IoT nodes need TLS, broker authentication, OTA authentication/signature validation, reconnect backoff and safe handling of failed updates.