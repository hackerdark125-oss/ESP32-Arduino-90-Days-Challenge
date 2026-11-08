# Day 81: Scrolling road

**Goal:** Create the illusion of movement by scrolling dashed lane markings.

## Wiring and libraries
Use the OLED wiring from Day 79 and install Adafruit SSD1306/GFX.

## Run
Upload the sketch. The lane divider dashes move downward while the player's car remains near the bottom.

## Concepts
The road offset advances by a fixed number of pixels and wraps around after one dash period. This is a simple scrolling background technique.