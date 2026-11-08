# Day 72: Hall sensor and internal temperature

**Goal:** Explore built-in sensors available on the original ESP32.

## Compatibility
This lesson is specifically for the original dual-core ESP32-WROOM-32. Hall sensor support is not present on many newer ESP32 variants. The internal temperature reading is a rough chip-temperature estimate, not an ambient thermometer.

## Run
Upload and open Serial Monitor at 115200 baud. Move a small magnet near the ESP32 module area without touching or shorting the board; observe whether the Hall reading changes.

## Important
Do not use the internal temperature estimate for safety control or precision measurements. Exact API support depends on Arduino-ESP32 core version.