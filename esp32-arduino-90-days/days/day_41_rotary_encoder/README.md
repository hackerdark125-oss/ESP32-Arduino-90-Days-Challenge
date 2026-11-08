# Day 41: Rotary encoder

**Goal:** Read rotation direction, position and the encoder's push switch.

## Wiring
For a common KY-040-style encoder:
- CLK/A → GPIO 32
- DT/B → GPIO 33
- SW → GPIO 25
- GND → GND
- VCC → module voltage compatible with 3.3 V ESP32 logic (prefer 3.3 V)

## Run
Upload and open Serial Monitor at 115200 baud. Rotate the shaft and press the switch.

## Concepts
The sketch detects a falling edge on channel A and reads channel B to infer direction. This simple polling decoder is suitable for learning but may miss fast turns and does not fully debounce the rotary contacts. More robust projects use a state-table decoder or interrupts.