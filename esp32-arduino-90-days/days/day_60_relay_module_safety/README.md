# Day 60: Relay module safety

**Goal:** Understand safe GPIO control of a relay module using a button, without switching mains power.

## Wiring
- Relay module IN → GPIO 26
- Relay module VCC/GND → exactly as specified by its datasheet
- Button between GPIO 27 and GND
- Use the relay contacts only with a harmless, isolated low-voltage indicator circuit if you have the correct rated hardware.

## Important safety rules
- **Do not connect household AC mains** for this exercise.
- Never drive a bare relay coil directly from an ESP32 GPIO. Use a proper driver/module with flyback protection.
- Confirm whether the module input is active-low or active-high; adjust `RELAY_ACTIVE_LOW` only after checking its documentation.
- Keep relay supply and ESP32 grounds/reference wiring correct for the module design.
- Mains switching requires certified isolation, enclosure, fusing, strain relief and qualified electrical work.

## Run
Press the button to energize/release the relay module. The Serial Monitor reports the state.