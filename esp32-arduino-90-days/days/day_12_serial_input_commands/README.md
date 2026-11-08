# Day 12: Serial input commands

**Goal:** Send text commands from the Arduino IDE Serial Monitor to control an LED.

## Wiring
GPIO 18 → 220–330 Ω resistor → LED anode; LED cathode → GND.

## Run
1. Upload the sketch.
2. Open Serial Monitor at **115200 baud**.
3. Set the line ending to **Newline** (or Both NL & CR).
4. Type one command and press Enter.

| Command | Action |
|---|---|
| ON | Turn LED on |
| OFF | Turn LED off |
| TOGGLE | Change current LED state |
| STATUS | Print current state |
| HELP | Show commands |

## Concepts
`Serial.available()` checks for incoming bytes. `readStringUntil('\n')` reads a line, and `trim()` removes extra whitespace. The Serial read timeout can make the loop pause briefly while waiting for the line ending.