# Day 32: OLED graphics

**Goal:** Draw lines, rectangles, circles and rounded rectangles.

## Wiring and libraries
Use the same I2C wiring as Day 31: SDA 21, SCL 22, GND and supported VCC. Install Adafruit SSD1306 and Adafruit GFX.

## Run
Upload the sketch. It draws several geometric shapes and a short label on the OLED.

## Concepts
Adafruit GFX provides drawing primitives. Coordinates start at the top-left corner (0,0); the display is 128 pixels wide and 64 pixels high. Drawing changes the local buffer; `display.display()` sends it to the screen.