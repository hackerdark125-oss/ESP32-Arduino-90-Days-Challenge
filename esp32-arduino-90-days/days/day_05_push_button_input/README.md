# Day 5: Push button input

**Goal:** Read a push button using `digitalRead()` and `INPUT_PULLUP`.

## Wiring
- One side of the button → GPIO 19
- Other side of the button → GND
- LED: GPIO 18 → 220–330 Ω resistor → LED anode; LED cathode → GND

## Run
Upload the sketch. The LED turns on while the button is pressed. Serial Monitor at 115200 baud prints a message.

## Concepts
The internal pull-up holds the input HIGH when the button is released. Pressing the button connects the pin to GND, so it reads LOW. This is called active-low logic.

This simple lesson does not debounce the button; Day 6 adds software debounce.