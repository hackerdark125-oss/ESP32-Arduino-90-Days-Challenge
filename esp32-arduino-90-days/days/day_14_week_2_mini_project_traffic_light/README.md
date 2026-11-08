# Day 14: Traffic light mini project

**Goal:** Build a three-LED traffic light using an enum state machine and `millis()`.

## Parts and wiring
Use three LEDs and three separate 220–330 Ω resistors.
- GPIO 16 → resistor → red LED anode
- GPIO 17 → resistor → yellow LED anode
- GPIO 18 → resistor → green LED anode
- All LED cathodes → GND

## Expected sequence
1. Red for 4 seconds
2. Green for 4 seconds
3. Yellow for 1.5 seconds
4. Repeat

Serial Monitor at 115200 baud prints each state.

## Concepts
The `TrafficState` enum makes the current state explicit. `enterState()` changes the outputs and records the start time. The loop checks elapsed time without blocking, so other features can be added later.

**Safety:** This is a learning model only, not a real road signal controller.