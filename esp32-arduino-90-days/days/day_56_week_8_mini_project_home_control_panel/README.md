# Day 56: Home control panel mini project

**Goal:** Build a local web panel that switches two low-voltage outputs and displays an analog reading.

## Wiring
- Output 1 LED: GPIO 18 → 220–330 Ω resistor → LED → GND
- Output 2 LED: GPIO 19 → 220–330 Ω resistor → LED → GND
- Potentiometer wiper → GPIO 34; outer legs → 3V3 and GND

## Run
Set Wi-Fi credentials, upload, and open the printed IP address on the same network. Use the links to switch each LED and view the ADC reading.

## Safety
This is a low-voltage learning demo. Do **not** connect mains appliances or bare relay contacts to this circuit. Real relay projects require correctly rated isolated modules, enclosure, fusing and qualified electrical work. Add authentication before exposing any control endpoint beyond a trusted local test network.