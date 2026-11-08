# Day 86: High-score storage

**Goal:** Save the best score in ESP32 NVS so it survives power loss.

## Run
Use the OLED and two buttons from earlier capstone lessons. The best score is loaded at startup and saved only when a new record is achieved. After a crash, press the left button to restart.

## Concepts
The Preferences library stores an integer under namespace `race-game` and key `high`. Flash writes are performed only when the record improves, not every frame.

## Reset the record
You can clear the stored key with a separate Preferences sketch or erase the ESP32 flash. Be aware that erasing flash removes other stored settings too.