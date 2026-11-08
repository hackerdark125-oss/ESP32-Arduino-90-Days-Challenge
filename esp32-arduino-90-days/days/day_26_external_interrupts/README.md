# Day 26: External interrupts

**Goal:** Respond to a button edge using `attachInterrupt()`.

## Wiring
Button between GPIO 27 and GND. Optional LED: GPIO 18 → 220–330 Ω resistor → LED anode; cathode → GND.

## Run
Upload and press the button. The LED toggles and Serial Monitor (115200 baud) reports the state.

## Concepts and rules
The interrupt service routine (ISR) only sets a `volatile` flag. The main loop performs Serial output and LED work. Keep ISRs short: do not call `delay()`, print to Serial, or perform lengthy operations inside them.

A simple 200 ms acceptance interval suppresses repeated button events. This is an introductory software guard, not a replacement for a full hardware debounce circuit.