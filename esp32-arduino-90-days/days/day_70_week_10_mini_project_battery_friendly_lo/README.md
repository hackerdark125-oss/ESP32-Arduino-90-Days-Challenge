# Day 70: Battery-friendly logger mini project

**Goal:** Wake periodically, read an analog input, save a counter in NVS, then return to deep sleep.

## Wiring
Potentiometer outer legs → 3V3 and GND; wiper → GPIO 34.

## Run
Upload and open Serial Monitor at 115200 baud. The ESP32 logs one ADC reading, increments a persistent sample counter, then sleeps for 15 seconds. It restarts and repeats after waking.

## Concepts
Deep sleep reduces average power by keeping the chip asleep between samples. Preferences stores the sample count across resets. This is a teaching example, not a complete battery-optimized product; regulator quiescent current, sensor power, wake time and battery chemistry also matter.