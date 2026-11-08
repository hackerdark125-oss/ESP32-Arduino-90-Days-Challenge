# Day 55: LittleFS flash storage

**Goal:** Save and read a small text file in the ESP32's internal flash filesystem.

## Run
Upload the sketch and open Serial Monitor at 115200 baud. The ESP32 mounts LittleFS, writes `/notes.txt`, then reads it back.

## Concepts
LittleFS stores files in a flash partition. The `LittleFS.begin(true)` call may format the filesystem if mounting fails, which erases existing LittleFS contents. Use that option carefully in projects with important stored data.

No external wiring or extra library is required for supported ESP32 Arduino core versions.