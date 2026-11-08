# Day 22: LDR light sensor

**Goal:** Detect relative light level with a light-dependent resistor.

## Wiring
Make a voltage divider: **3V3 → LDR → GPIO 34 → 10 kΩ resistor → GND**. The ADC reads the midpoint. Keep the ADC voltage between 0 and 3.3 V.

## Run
Upload and open Serial Monitor at 115200 baud. Cover the LDR and shine a light on it. The reading should change. With this wiring, readings usually rise as light increases, but the exact range depends on the LDR and resistor.

## Exercise
Record readings in bright light and darkness, then choose a threshold based on your measured values. Do not assume the example threshold fits every LDR.