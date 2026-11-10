# Day 8: Variables, types and functions

**Phase:** Foundations (Days 1–14)  
**Goal:** Learn common Arduino C++ data types and write reusable helper functions.

This is a Serial Monitor exercise for the ESP32-WROOM-32. No external LED, button, or sensor is required.

## What you will learn

- Store whole numbers with `int`.
- Store decimal values with `float`.
- Store true/false values with `bool`.
- Store a single character with `char`.
- Store text literals with `const char*`.
- Use `unsigned long` for values such as the millisecond counter returned by `millis()`.
- Create `void` functions that perform an action.
- Pass parameters into functions and return calculated values.

## Parts used

- ESP32-WROOM-32 development board
- USB data cable
- Computer with Arduino IDE

## Wiring / pins

No external wiring is needed. Connect the ESP32 to your computer using USB.

## Upload and run

1. Open `day_08_variables_types_and_functions.ino` in Arduino IDE.
2. Select your ESP32 board and its serial port.
3. Upload the sketch.
4. Open Serial Monitor and select **115200 baud**.
5. Read the printed variable examples and average-temperature calculation.

## Expected Serial Monitor output

The exact boot-time value will vary.

```text
==============================
VARIABLES AND DATA TYPES
==============================
Project: ESP32 Day 8
Ready: true
Status code: A
Boot time (unsigned long): ... ms

==============================
FUNCTIONS AND CALCULATIONS
==============================
Number of readings (int): 4
Average temperature (float): 25.75 C
Description: Comfortable

==============================
DAY 8 COMPLETE: DEMO FINISHED
==============================
```

## Functions explained

| Function | Purpose |
|---|---|
| `printHeading()` | Prints a heading; accepts text and returns nothing |
| `calculateAverage()` | Accepts an array and count; returns a `float` |
| `describeTemperature()` | Accepts a `float`; returns a text description |
| `printProjectStatus()` | Prints project variables |
| `printReadingSummary()` | Combines calculation and printing |

## Try these changes

1. Change the four values in `readings` and upload again.
2. Change `projectReady` to `false` and observe the output.
3. Change the temperature thresholds in `describeTemperature()`.
4. Add another helper function that prints the minimum reading.

## Problems and fixes

- **Unreadable Serial output:** Set Serial Monitor to 115200 baud.
- **No output:** Check the selected board and port, then press the ESP32 reset button once after upload.
- **Compilation error:** Check that the sketch filename and folder match and that all braces and semicolons are present.


