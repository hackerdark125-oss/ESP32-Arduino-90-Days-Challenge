# Day 33: OLED animation

**Goal:** Animate a bouncing ball at an approximately 30 FPS update rate.

## Wiring and libraries
Use the Day 31 SSD1306 I2C wiring and Adafruit SSD1306/GFX libraries.

## Run
Upload the sketch. A small circle should bounce around the screen.

## Concepts
The sketch updates only when at least 33 ms has elapsed, using `millis()` rather than a blocking frame delay. The frame rate is approximate and depends on I2C transfer time. The ball reverses direction at the screen edges.

## Exercise
Change `dx`, `dy`, and `FRAME_MS` to experiment with speed.