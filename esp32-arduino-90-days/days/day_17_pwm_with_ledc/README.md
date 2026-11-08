# Day 17: PWM with LEDC

**Goal:** Fade an LED using ESP32 hardware PWM.

## Wiring
GPIO 18 → 220–330 Ω resistor → LED anode; LED cathode → GND.

## Run
This sketch uses the Arduino-ESP32 **3.x** LEDC API: `ledcAttach(pin, frequency, resolution)` and `ledcWrite(pin, duty)`. Upload and watch the LED fade up and down.

## Concepts
At 8-bit resolution, duty values range from 0 (off) to 255 (full duty). PWM changes average LED power without using `analogWrite()`.

If your installed ESP32 core is 2.x, the LEDC API is different; update the board package or adapt the sketch for that version.