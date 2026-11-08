# Day 3: Serial Monitor basics

**Goal:** Send text and numbers from the ESP32 to the Arduino IDE Serial Monitor.

## Run
Upload the sketch, then open Serial Monitor and select **115200 baud**. A counter and the elapsed time since boot should appear once per second.

## Concepts
`Serial.begin(115200)` starts the serial connection. `Serial.print()` writes without a newline; `Serial.println()` adds one. The baud rate selected in Serial Monitor must match the sketch.

## Exercise
Print your own message and change the update interval.