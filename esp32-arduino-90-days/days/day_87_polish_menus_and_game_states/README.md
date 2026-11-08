# Day 87: Menus and game states

**Goal:** Add clear title, playing and game-over states.

## Controls
- Right button GPIO 33 starts from the title screen.
- Left/right buttons GPIO 32/33 change lanes while playing.
- Either button returns from game over to the title screen.

## Run
Use the SSD1306 OLED wiring and Adafruit libraries from earlier days. Upload and test each state transition.

## Concepts
An enum represents the current game state. Input and rendering behavior depend on that state, making the game easier to extend than a collection of unrelated flags.