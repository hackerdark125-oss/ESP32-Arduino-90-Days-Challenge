# Day 24: HC-SR04 ultrasonic distance sensor

**Goal:** Measure distance by timing the ultrasonic echo pulse.

## Wiring
- HC-SR04 VCC → 5 V; GND → ESP32 GND
- TRIG → GPIO 5
- ECHO → GPIO 18 **through a voltage divider or level shifter**

The HC-SR04 ECHO pin can output 5 V. Never connect it directly to an ESP32 GPIO. Example divider: ECHO → 1 kΩ → GPIO 18, and GPIO 18 → 2 kΩ → GND (approximately 3.3 V at the pin).

## Run
Upload and open Serial Monitor at 115200 baud. Place an object in front of the sensor. A timeout message appears when no echo is received within the timeout window.

## Formula
Distance in cm ≈ echo duration in microseconds × 0.0343 ÷ 2. The division by two accounts for the sound's outward and return journey.