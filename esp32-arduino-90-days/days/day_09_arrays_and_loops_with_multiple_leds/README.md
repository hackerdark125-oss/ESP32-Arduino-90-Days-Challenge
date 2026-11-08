# Day 9: Arrays and loops with multiple LEDs

**Goal:** Use an array and `for` loops to create a Knight Rider-style LED chase.

## Parts and wiring
Use five LEDs and five separate 220–330 Ω resistors.
- GPIO 16 → resistor → LED 1 anode; LED cathode → GND
- GPIO 17 → resistor → LED 2 anode; LED cathode → GND
- GPIO 18 → resistor → LED 3 anode; LED cathode → GND
- GPIO 19 → resistor → LED 4 anode; LED cathode → GND
- GPIO 21 → resistor → LED 5 anode; LED cathode → GND

## Run
Open the sketch, select your ESP32 board and port, upload, and watch the LEDs. No Serial Monitor is required; if opened, use 115200 baud.

## Concepts
- `ledPins[]` stores all output pin numbers.
- `LED_COUNT` calculates the number of elements.
- The first loop scans forward; the second scans backward without repeating the endpoints.
- Each LED has its own current-limiting resistor.

**Safety:** Never connect an LED directly to a GPIO without a series resistor.