# Day 28: Parking sensor mini project

**Goal:** Combine an ultrasonic sensor, three distance LEDs and a beeper.

## Wiring
- HC-SR04 VCC → 5 V; GND → ESP32 GND
- TRIG → GPIO 5
- ECHO → GPIO 18 **through a voltage divider/level shifter** (HC-SR04 ECHO can be 5 V)
- Green LED → GPIO 19 through its own 220–330 Ω resistor
- Yellow LED → GPIO 17 through its own 220–330 Ω resistor
- Red LED → GPIO 16 through its own 220–330 Ω resistor
- Active buzzer module input → GPIO 25, only if its input is 3.3 V-compatible; otherwise use a transistor driver

All LED cathodes → GND. All module grounds must be common.

## Behavior
- More than 60 cm: green
- 31–60 cm: yellow
- 11–30 cm: red with slow beeps
- 10 cm or less: red with faster beeps

Thresholds are teaching defaults; tune them for your sensor and setup.

## Safety
Never connect the HC-SR04 ECHO output directly to an ESP32 pin. Use a proper divider or logic-level shifter. Do not drive a large buzzer directly from a GPIO.