# Day 83: Collision detection

**Goal:** Detect when the player's car overlaps an obstacle.

## Controls
Left button GPIO 32 to GND; right button GPIO 33 to GND. OLED uses SDA 21 and SCL 22.

## Run
Upload and move between lanes to avoid the falling obstacle. When the player and obstacle rectangles overlap, the game displays CRASH and stops movement.

## Concepts
The `overlaps()` helper uses axis-aligned rectangle collision: two rectangles collide when their horizontal and vertical ranges overlap. This is simple and efficient for a small 2D game.