# Day 18: RGB LED color mixing

**Goal:** Mix red, green and blue using three independent PWM channels.

## Wiring
For a **common-cathode** RGB LED:
- Common cathode → GND
- Red anode → 220–330 Ω resistor → GPIO 25
- Green anode → 220–330 Ω resistor → GPIO 26
- Blue anode → 220–330 Ω resistor → GPIO 27

Use one resistor per color channel. If your LED is common-anode, this sketch's logic must be inverted.

## Run
Uses Arduino-ESP32 core 3.x LEDC functions. Upload and observe the sequence of colors.

## Exercise
Change the three values in `setColor(red, green, blue)`. Each channel ranges from 0 to 255.