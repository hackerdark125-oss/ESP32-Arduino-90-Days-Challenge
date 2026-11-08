# Day 78: Capstone planning

**Project:** Build a simple 3-lane OLED racing game for the ESP32-WROOM-32.

## Hardware
- ESP32-WROOM-32 development board
- 128×64 SSD1306 I2C OLED
- Two momentary push buttons
- Optional passive piezo buzzer
- Breadboard, jumper wires and USB power

## Wiring plan
- OLED SDA 21, SCL 22, GND, supported VCC
- Left button GPIO 32 to GND
- Right button GPIO 33 to GND
- Optional passive buzzer GPIO 25 to GND

Buttons use INPUT_PULLUP. No external pull-up is required for normal awake operation.

## Software architecture
- Fixed-rate update loop
- Three road lanes and a player car
- Obstacles spawn and move downward
- Rectangle collision detection
- Score and increasing difficulty
- Sound effects and NVS high-score storage
- Menu, playing and game-over states

## Libraries
Adafruit SSD1306, Adafruit GFX. The later high-score lesson uses Preferences, included with the ESP32 core.

## Safety
Use only a small passive buzzer on a suitable GPIO or a driver. Do not connect motors or high-current loads directly to ESP32 pins.