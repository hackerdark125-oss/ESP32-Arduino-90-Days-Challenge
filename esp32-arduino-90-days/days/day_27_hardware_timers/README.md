# Day 27: Hardware timers

**Goal:** Use an ESP32 hardware timer to generate a periodic event.

## Run
This sketch requires Arduino-ESP32 **core 3.x**. Upload and open Serial Monitor at 115200 baud. A counter should increase once per second.

## How it works
`timerBegin(1000000)` creates a timer with a 1 MHz tick frequency. `timerAlarm(..., 1000000, true, 0)` schedules a repeating one-second alarm. The callback increments a `volatile` counter; Serial printing happens in `loop()`, not in the callback.

## Important
Timer APIs changed between Arduino-ESP32 core 2.x and 3.x. This example targets core 3.x. Keep timer callbacks very short and avoid blocking calls or Serial output inside them.