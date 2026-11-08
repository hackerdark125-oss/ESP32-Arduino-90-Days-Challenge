# Day 59: MQTT remote control

**Goal:** Subscribe to an MQTT topic and switch an LED using ON/OFF messages.

## Wiring
GPIO 18 → 220–330 Ω resistor → LED anode; LED cathode → GND.

## Setup
Install PubSubClient, enter Wi-Fi credentials and choose a unique topic. Upload and open Serial Monitor at 115200 baud.

## Test
Use an MQTT client to publish the text `ON` or `OFF` to the exact topic. The ESP32 changes the LED state.

## Safety
This demo controls only an LED. Do not use unauthenticated public MQTT to control locks, heaters, motors, mains appliances or safety-critical equipment. Production control needs TLS, authentication, authorization and safe-state handling.