# Day 31: SSD1306 OLED basics

**Goal:** Initialize a 128×64 I2C OLED and display text.

## Wiring
OLED SDA → GPIO 21; SCL → GPIO 22; GND → GND; VCC → the voltage supported by your OLED breakout (many accept 3.3 V).

## Libraries
Install **Adafruit SSD1306** and **Adafruit GFX Library** from Arduino IDE Library Manager.

## Run
Upload the sketch. It tries I2C address 0x3C. If the display remains blank, run the Day 29 scanner and update the address if needed. The sketch prints an error to Serial Monitor at 115200 baud if initialization fails.

## Concepts
The display uses a framebuffer. Draw text, then call `display.display()` to transfer the buffer to the OLED.