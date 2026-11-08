# Day 4: External LED and resistor

**Goal:** Connect and blink an external LED using a current-limiting resistor.

## Parts
ESP32-WROOM-32, one LED, one 220–330 Ω resistor, breadboard and jumper wires.

## Wiring
GPIO 18 → resistor → LED anode (long leg). LED cathode (short leg) → GND.

## Run
Upload the sketch. The LED should turn on for half a second and off for half a second.

## Safety
Always use a series resistor with an ordinary LED. Never connect an LED directly between a GPIO and GND. Never connect 5 V to an ESP32 GPIO.