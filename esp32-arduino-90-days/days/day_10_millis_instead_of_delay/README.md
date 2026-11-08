# Day 10: millis() instead of delay()

**Goal:** Blink an LED without pausing the whole program.

## Wiring
GPIO 18 → 220–330 Ω resistor → LED anode. LED cathode → GND.

## Run
Upload the sketch to the ESP32. The LED changes state every 500 ms.

## Key idea
`delay(500)` blocks the processor from doing other work in the loop. `millis()` returns the number of milliseconds since startup. Comparing elapsed time with `now - previousBlinkTime` allows other code to run between LED updates.

Use unsigned time variables and subtraction for rollover-safe elapsed-time checks.

## Exercise
Change `BLINK_INTERVAL_MS` to 100, 1000, and 2000 and observe the speed.