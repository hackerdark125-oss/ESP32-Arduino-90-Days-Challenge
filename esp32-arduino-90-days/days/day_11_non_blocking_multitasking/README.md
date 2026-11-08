# Day 11: Non-blocking multitasking

**Goal:** Run two independent timed jobs without using `delay()`.

## Wiring
- GPIO 18 → resistor (220–330 Ω) → LED 1 anode; cathode → GND
- GPIO 19 → resistor (220–330 Ω) → LED 2 anode; cathode → GND

## Expected result
LED 1 toggles every 300 ms and LED 2 every 1000 ms. Their timing does not block each other.

## Concepts
Each `BlinkTask` stores its own pin, interval, last-change time and state. The main loop checks both tasks on every pass.

This is cooperative multitasking, not a separate FreeRTOS task. It is a useful stepping stone before the ESP32 FreeRTOS lessons.

## Exercise
Add a third LED on GPIO 21 with a 1500 ms interval and add it to the `tasks` array.