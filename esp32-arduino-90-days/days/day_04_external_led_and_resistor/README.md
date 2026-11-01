# Day 4: External LED and resistor

**Phase:** Phase 1: Foundations (Days 1-14)
**Goal:** Wire an LED on a breadboard safely

## What I learned
-Learned how to connect an external LED to the ESP32.

Understood LED polarity (positive and negative legs).

Learned why a resistor is needed to protect the LED.

Practised using a breadboard for circuit connections.

Learned how to control an external LED using digitalWrite()

## Parts used
-ESP32 development board

External LED

220Ω resistor

Breadboard

Jumper wires

USB cable

## Wiring / pins
-LED positive (long leg) → GPIO 23 through a 220Ω resistor.

LED negative (short leg) → GND.

ESP32 connected to the computer using USB.

## Problems and fixes
-Checked LED polarity when it didn't turn on.

Checked breadboard connections.

Verified the GPIO pin number in the code.

Made sure the resistor was connected in series with the LED.

## Result

Successfully connected an external LED to the ESP32 and controlled it using Arduino code.
