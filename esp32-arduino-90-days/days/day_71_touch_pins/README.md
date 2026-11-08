# Day 71: Capacitive touch pins

**Goal:** Detect a finger using the ESP32's built-in capacitive touch sensor.

## Compatibility
This example targets the original ESP32-WROOM-32 touch peripheral. Touch support and APIs differ on newer ESP32 variants.

## Run
Upload and open Serial Monitor at 115200 baud. Touch the exposed GPIO 4 pad carefully and observe the raw reading.

## Concepts
The original ESP32 touch sensor measures capacitance. Touch usually lowers the reported value. The threshold is estimated from a startup baseline and may need tuning for your board, wiring and environment.

Do not connect the touch pin to 5 V. Avoid touching exposed electronics while the board is connected to other equipment.