# Day 35: Sensor dashboard on OLED

**Goal:** Combine an analog sensor input and an OLED display into a live dashboard.

## Wiring
- Potentiometer outer legs → 3V3 and GND; wiper → GPIO 34.
- SSD1306 OLED SDA → GPIO 21; SCL → GPIO 22; GND → GND; VCC → supported voltage.

## Libraries
Install Adafruit SSD1306 and Adafruit GFX.

## Run
Upload and turn the potentiometer. The OLED displays the ADC value, an approximate percentage and a bar graph. Serial Monitor uses 115200 baud for initialization errors.

## Concepts
This mini project combines ADC sampling, value mapping, text rendering and simple graphics. The percentage is a scaled raw reading, not a calibrated physical measurement.