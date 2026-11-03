# Day 6: Button debounce

**Phase:** Phase 1: Foundations (Days 1-14)
**Goal:** Handle bouncing in software

## What I learned
-Learned what button bouncing is and why it happens.



Understood that a physical push button can produce multiple signals from a single press.



Learned how to use millis() to create a debounce delay.



Understood how to detect a stable button press.



Learned how software debounce prevents unwanted multiple triggers.

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

## Problems and fixes
-Problem: One button press sometimes triggered multiple times.
- Fix: Added software debounce logic.



Problem: Button readings changed rapidly.
- Fix: Used a debounce interval of 50 milliseconds.



Problem: LED state changed unexpectedly.
- Fix: Checked the button's stable state before changing the LED.

## Result
(Add a photo, GIF or video link)
