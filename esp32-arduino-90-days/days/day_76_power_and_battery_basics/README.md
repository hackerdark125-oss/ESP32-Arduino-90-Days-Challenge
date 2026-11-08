# Day 76: Power and battery basics

**Goal:** Understand a simple voltage divider and estimate battery voltage safely.

## Divider example
For a protected low-voltage battery measurement only:
- Battery positive → 100 kΩ resistor → GPIO 34
- GPIO 34 → 100 kΩ resistor → GND
- Battery negative → ESP32 GND

With equal resistors, the ADC sees about half the battery voltage. Use resistors with suitable tolerance and power rating. Add a small capacitor from ADC pin to GND if needed for noise reduction.

## Critical safety
Never connect a LiPo cell directly to an ESP32 GPIO. Do not charge a cell through this circuit. Use a proper protected battery, charger and regulator. Check the divider voltage under maximum battery voltage before connecting the ESP32.

## Run
Upload and open Serial Monitor at 115200 baud. The voltage estimate is approximate; ESP32 ADC calibration and resistor tolerances affect accuracy.