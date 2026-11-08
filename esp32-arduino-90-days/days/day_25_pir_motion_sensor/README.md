# Day 25: PIR motion sensor

**Goal:** Detect movement using a passive infrared sensor.

## Wiring
- PIR VCC → module's rated supply (many modules accept 5 V; check its label/datasheet)
- PIR GND → ESP32 GND
- PIR OUT → GPIO 27
- Optional indicator LED: GPIO 18 → 220–330 Ω resistor → LED anode; cathode → GND

Check that the PIR OUT signal is 3.3 V-compatible before connecting it to the ESP32.

## Run
Upload and open Serial Monitor at 115200 baud. Allow the PIR module to warm up and stabilize (often 30–60 seconds). Walk across its field of view.

## Concepts
The sketch reacts only when the digital motion state changes, avoiding repeated messages every loop.