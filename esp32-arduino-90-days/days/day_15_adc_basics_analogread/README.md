# Day 15: ADC basics with analogRead

**Goal:** Read a potentiometer using the ESP32's 12-bit ADC.

## Wiring
Potentiometer outer legs → **3V3** and **GND**. Middle leg (wiper) → **GPIO 34**. Do not connect the potentiometer to 5 V.

## Run
Upload and open Serial Monitor at 115200 baud. Turn the knob and watch the raw value change from near 0 to near 4095.

## Concepts
`analogReadResolution(12)` selects a 12-bit raw scale. GPIO 34 is input-only and belongs to ADC1 on the classic ESP32. The voltage calculation is an estimate; ADC readings require calibration for accurate voltage measurement.

**Safety:** Keep the ADC input within the ESP32's permitted range (never above 3.3 V).