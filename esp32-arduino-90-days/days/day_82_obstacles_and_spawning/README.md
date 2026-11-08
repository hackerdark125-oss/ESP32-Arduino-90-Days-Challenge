# Day 82: Obstacles and spawning

**Goal:** Create obstacles that appear in random lanes and move down the road.

## Wiring and libraries
Use the OLED from Day 79. No extra wiring is needed.

## Run
Upload the sketch. A rectangular obstacle repeatedly spawns above the screen in a random lane and moves downward.

## Concepts
The obstacle is represented by a lane index and a Y coordinate. When it leaves the screen, it is reset above the top and assigned a new random lane. The random seed uses an unconnected ADC input; results are pseudo-random, not cryptographically secure.