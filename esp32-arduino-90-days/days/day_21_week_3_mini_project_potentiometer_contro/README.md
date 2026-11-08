# Day 21: Potentiometer-controlled light

**Goal:** Combine ADC input and PWM output to control LED brightness.

## Wiring
- Potentiometer outer legs → 3V3 and GND; center wiper → GPIO 34.
- GPIO 18 → 220–330 Ω resistor → LED anode; LED cathode → GND.

## Run
Upload and rotate the potentiometer. The LED should smoothly change brightness. Serial Monitor at 115200 shows the raw ADC reading and PWM duty.

## Concepts
`analogRead()` reads the knob position. `map()` converts 0–4095 into 0–255, and LEDC outputs the PWM duty. The sketch uses the Arduino-ESP32 core 3.x LEDC API.

**Safety:** Do not power the potentiometer from 5 V; keep the wiper within 0–3.3 V.