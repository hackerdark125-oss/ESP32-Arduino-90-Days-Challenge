# Day 85: Sound effects

**Goal:** Add short tones for scoring and collision events.

## Wiring
Passive piezo buzzer positive → GPIO 25; negative → GND. Use a small piezo element, not a low-impedance speaker.

## Run
Play the game. A short high tone plays when an obstacle is passed; a lower tone plays after a collision.

## Concepts
The sketch uses LEDC tone output. The simple `beep()` helper uses a short delay, so sound briefly pauses the game loop. A polished game should schedule tones non-blockingly with `millis()`.