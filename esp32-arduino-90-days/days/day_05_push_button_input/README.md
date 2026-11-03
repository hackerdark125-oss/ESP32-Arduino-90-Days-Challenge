# Day 5: Push button input

**Phase:** Phase 1: Foundations (Days 1-14)
**Goal:** Read digitalRead with INPUT_PULLUP

## What I learned
-Learned how to read input from a push button using digitalRead().



Understood how INPUT_PULLUP works.



Learned that the button returns HIGH when not pressed and LOW when pressed.



Understood how to use conditional statements (if-else) to detect button presses.



Learned how to control an LED using button input.

## Parts used
-Arduino Uno R3



Push button



LED



220Ω resistor



Breadboard



Jumper wires



USB cable

## Wiring / pins
-Component	Arduino Pin
Push button	Pin 2 and GND
LED positive (+)	Pin 13
LED negative (-)	GND

Important: INPUT_PULLUP enables the internal pull-up resistor, so an external resistor for the button is not required.

## Problems and fixes
-Problem: Button readings were reversed.
- Fix: Understood that INPUT_PULLUP reads LOW when pressed.



Problem: LED was not responding correctly.
- Fix: Checked button connections and pin configuration.



Problem: Unstable button readings.
- Fix: Used INPUT_PULLUP instead of a floating INPUT pin.

## Result
Successfully read push button input using digitalRead() and INPUT_PULLUP. Tested button presses and controlled the LED accordingly.
