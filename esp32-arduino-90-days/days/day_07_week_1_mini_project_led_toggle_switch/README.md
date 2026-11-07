# Day 7: Week 1 mini project: LED toggle switch

**Phase:** Phase 1: Foundations (Days 1-14)
**Goal:** Toggle LED state with one button

## What I learned
- I learned how to combine button input and LED output in one small project.
- I learned that `INPUT_PULLUP` makes the button read `LOW` when it is pressed.
- I learned how to keep an LED's ON/OFF state using a boolean variable.
- I learned why debounce is needed so one physical press does not trigger several toggles.
- I used `millis()` to wait for a stable button reading without blocking the loop.

## Parts used
- ESP32-WROOM-32 development board
- Push button
- External LED
- 220Ω resistor
- Breadboard and jumper wires
- USB cable

## Wiring / pins
| Component | ESP32 connection |
|---|---|
| Push button terminal 1 | GPIO 18 |
| Push button terminal 2 | GND |
| LED anode (long leg) | GPIO 23 through a 220Ω resistor |
| LED cathode (short leg) | GND |

The button uses the ESP32's internal pull-up, so no external button resistor is needed. The LED must have a series resistor. ESP32 GPIO pins are 3.3V logic; do not connect a GPIO to 5V.

## Problems and fixes
- If the button always reads as pressed, check that it is wired between GPIO 18 and GND.
- If the LED does not turn on, check its polarity and the series resistor connection.
- If one press causes more than one toggle, check the button and breadboard connections; the sketch uses a 50 ms debounce interval.

## Result
**Pending hardware test.** Upload the sketch, press and release the button several times, and confirm that the LED changes state once per press. Add a real photo or video after testing.
