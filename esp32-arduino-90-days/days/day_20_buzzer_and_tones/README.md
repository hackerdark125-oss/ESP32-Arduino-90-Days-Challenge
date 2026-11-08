# Day 20: Buzzer and tones

**Goal:** Generate different pitches with a passive piezo buzzer.

## Wiring
Passive buzzer positive → GPIO 25; negative → GND. If using a larger speaker or buzzer module, use a suitable driver transistor and follow its datasheet.

## Run
The sketch uses the Arduino-ESP32 core 3.x LEDC tone functions to play four notes. An **active** buzzer generally makes one fixed tone when powered; use a passive buzzer for pitch control.

## Concepts
Frequency (Hz) controls pitch and duration controls how long the note plays. Do not connect a low-impedance speaker directly to a GPIO.