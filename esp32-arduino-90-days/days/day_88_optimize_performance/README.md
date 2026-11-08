# Day 88: Optimize performance

**Goal:** Use a fixed update interval and reduce unnecessary work in the game loop.

## Run
Upload the sketch and observe the game at an approximately 30 Hz target update rate.

## Optimizations demonstrated
- Uses `micros()` for a stable target frame interval.
- Uses fixed-size arrays and integer state instead of repeated dynamic object creation.
- Keeps rendering and game-state data small for a 128×64 display.
- Avoids Serial printing inside the frame loop.

## Performance note
The OLED transfer itself takes time, so 30 FPS is a target, not a guaranteed measured result. For a real benchmark, measure frame duration over many frames and report the measured average and worst case rather than claiming a frame rate without testing.