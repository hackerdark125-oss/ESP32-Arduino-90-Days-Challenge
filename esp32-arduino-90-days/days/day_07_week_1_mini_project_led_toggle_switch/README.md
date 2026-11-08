# Day 7: Week 1 mini project — LED toggle switch

**Phase:** Foundations (Days 1–14)  
**Goal:** Use one push button to switch an external LED on and off.

This project brings together the button input from Day 5 and the debounce logic from Day 6. A short press changes the LED state; holding the button does not repeatedly toggle it.

## Parts

- ESP32-WROOM-32 development board
- Momentary push button
- External LED
- 220 Ω resistor
- Breadboard and jumper wires
- USB data cable

## Wiring

| Part | Connection |
|---|---|
| Button terminal 1 | GPIO 18 |
| Button terminal 2 | GND |
| LED anode (long leg) | GPIO 23 through a 220 Ω resistor |
| LED cathode (short leg) | GND |

The button uses `INPUT_PULLUP`, so it needs no external pull-up resistor. With this wiring, the input is normally `HIGH` and becomes `LOW` when pressed.

**Safety:** ESP32 GPIO uses 3.3 V logic. Do not connect a GPIO directly to 5 V. Keep the LED's series resistor in place.

## Upload and try it

1. Open `day_07_week_1_mini_project_led_toggle_switch.ino` in Arduino IDE.
2. Select the ESP32 board and the correct serial port.
3. Check the button and LED wiring before connecting USB power.
4. Upload the sketch.
5. Open Serial Monitor at **115200 baud**.
6. Press and release the button. Each press should change the LED state once.

Expected Serial Monitor messages:

```text
Day 7: LED toggle switch ready
LED: ON
LED: OFF
LED: ON
```

The example above shows the intended output format, not a recorded hardware test.

## How the sketch works

- `INPUT_PULLUP` keeps the button input HIGH until the button connects it to GND.
- `lastRawReading` tracks immediate electrical changes.
- `lastChangeTime` records when the raw input last changed.
- The sketch accepts a new stable state only after it remains unchanged for 50 ms.
- The LED toggles only on the transition to the pressed state (`LOW`).

Using `millis()` for debounce keeps the main loop free; there is no blocking `delay()`.

## Troubleshooting

- **LED never lights:** Check LED polarity, the 220 Ω resistor, GPIO 23, and GND.
- **Button appears permanently pressed:** Check that the button bridges GPIO 18 and GND, and that it is not placed across the wrong breadboard rows.
- **One press toggles more than once:** Check for loose wiring or a poor button connection. The sketch uses a 50 ms debounce interval.
- **No Serial output:** Confirm the selected port and set Serial Monitor to 115200 baud.

## Before calling the day complete

Use [TEST_LOG.md](TEST_LOG.md) to record the actual board, upload, and button/LED checks. The repository should only be marked complete after the physical checks have been performed.
