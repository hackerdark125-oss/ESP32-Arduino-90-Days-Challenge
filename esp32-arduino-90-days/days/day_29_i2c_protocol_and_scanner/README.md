# Day 29: I2C protocol and scanner

**Goal:** Discover I2C device addresses connected to the ESP32.

## Wiring
Connect the module's SDA → GPIO 21, SCL → GPIO 22, GND → GND, and VCC to the module's supported voltage. Many I2C breakout boards include pull-up resistors; avoid adding multiple strong pull-ups.

## Run
Upload and open Serial Monitor at 115200 baud. The scanner checks addresses 1–126 every three seconds.

## Concepts
I2C uses SDA for data and SCL for clock. Each device responds to an address. If none are found, check power, ground, SDA/SCL orientation, voltage compatibility and the module's address.

**Safety:** Ensure I2C pull-ups do not pull ESP32 lines above 3.3 V.