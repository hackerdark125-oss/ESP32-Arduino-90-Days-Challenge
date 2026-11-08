# Day 84: Score and difficulty ramp

**Goal:** Award points when an obstacle passes and gradually increase its speed.

## Run
Use the OLED and two buttons from the previous capstone days. Avoid obstacles and watch the score rise. Every eight points, the obstacle speed increases up to a capped value.

## Concepts
Score is awarded when an obstacle leaves the screen. Difficulty is derived from score, keeping the rule simple and predictable. The collision helper is intentionally simplified to lane and vertical-position checks for this lesson.