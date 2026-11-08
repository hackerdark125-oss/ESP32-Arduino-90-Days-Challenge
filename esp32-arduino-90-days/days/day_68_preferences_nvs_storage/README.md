# Day 68: Preferences (NVS storage)

**Goal:** Store a small setting in non-volatile storage so it survives reboot.

## Run
Upload and open Serial Monitor at 115200 baud. Each reset increments the saved boot counter.

## Concepts
The Preferences library stores key/value data in ESP32 NVS. `getUInt()` reads a value with a default; `putUInt()` saves the updated value. Use a namespace to keep settings grouped.

## Note
Flash storage has finite write endurance. Do not write continuously in a fast loop; save only when a value changes or at sensible intervals.