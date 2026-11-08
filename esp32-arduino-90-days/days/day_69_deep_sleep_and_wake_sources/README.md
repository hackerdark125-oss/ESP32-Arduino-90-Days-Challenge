# Day 69: Deep sleep and wake sources

**Goal:** Put the ESP32 into deep sleep and wake it using a timer or button.

## Button wiring
Use an external 10 kΩ pull-up from GPIO 33 to 3V3 and a momentary button from GPIO 33 to GND. GPIO 33 is RTC-capable on the classic ESP32.

## Run
Upload and open Serial Monitor at 115200 baud. The ESP32 prints the wake cause, then enters deep sleep. It wakes after 10 seconds or when the button pulls GPIO 33 LOW.

## Concepts
Deep sleep shuts down much of the chip to reduce power. After wake, the program starts again from `setup()`; ordinary RAM variables do not retain their previous values.