# Day 37: UART and Serial2

**Goal:** Use the ESP32's second hardware UART independently of USB Serial.

## Wiring
For loopback, connect **TX2 GPIO 17 → RX2 GPIO 16** with one jumper. Do not connect TX to TX. No external voltage is needed for this test.

## Run
Upload and open Serial Monitor at 115200 baud. Every second the ESP32 sends a line through UART2 and reads it back through the jumper.

## Concepts
UART uses TX, RX and a shared ground. Both devices must use matching baud rate and frame settings. For a real external device, cross TX-to-RX and RX-to-TX, connect grounds, and confirm its logic voltage is 3.3 V-compatible.