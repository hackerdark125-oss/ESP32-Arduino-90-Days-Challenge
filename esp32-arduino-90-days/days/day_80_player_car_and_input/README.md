# Day 80: Player car and input

**Goal:** Move a player car between three lanes using two buttons.

## Wiring
- OLED SDA 21, SCL 22, GND and supported VCC.
- Left button between GPIO 32 and GND.
- Right button between GPIO 33 and GND.

## Run
Install Adafruit SSD1306 and GFX, upload, and press the buttons. The car moves left or right and stays within the three lanes.

## Concepts
The player position is represented by a lane index (0–2), not an arbitrary screen coordinate. Edge detection and a small repeat guard prevent one held button from moving too quickly.