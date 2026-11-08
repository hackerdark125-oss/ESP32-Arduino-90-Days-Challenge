# Day 42: Menu system mini project

**Goal:** Navigate an OLED menu with a rotary encoder and select an item with its push switch.

## Wiring
- SSD1306 OLED SDA 21, SCL 22, GND and supported VCC.
- Encoder CLK/A → GPIO 32; DT/B → GPIO 33; SW → GPIO 25; GND → GND; VCC → compatible 3.3 V logic.

## Libraries
Install Adafruit SSD1306 and Adafruit GFX.

## Run
Upload and rotate the encoder to move through Status, Settings, Sensors and About. Press the encoder switch to toggle a small selection indicator.

## Concepts
This combines input polling, menu index bounds/wraparound and OLED rendering. The simple rotary decoder may miss fast turns; improve it with a quadrature state machine for a more reliable interface.