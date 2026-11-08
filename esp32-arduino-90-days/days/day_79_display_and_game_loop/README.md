# Day 79: Display and game loop

**Goal:** Initialize the OLED and create a fixed-interval update loop.

## Wiring and libraries
OLED SDA → GPIO 21, SCL → GPIO 22, GND and supported VCC. Install Adafruit SSD1306 and Adafruit GFX.

## Run
Upload and observe the title screen and frame counter.

## Concepts
The loop updates at a target interval of 33 ms (about 30 updates per second) using `millis()`. It avoids long blocking delays. OLED transfer time limits the actual frame rate, so this is a target rather than a guarantee.