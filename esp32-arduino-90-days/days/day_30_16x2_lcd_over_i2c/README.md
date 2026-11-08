# Day 30: 16x2 LCD over I2C

**Goal:** Display text on a 16-column, 2-row LCD using an I2C backpack.

## Wiring
LCD SDA → GPIO 21; SCL → GPIO 22; GND → GND. Power the backpack at the voltage specified by its manufacturer. Confirm the I2C pull-ups are safe for 3.3 V ESP32 pins.

## Library
Install a compatible **LiquidCrystal_I2C** library through Arduino IDE Library Manager. Run the Day 29 scanner first. If your address is 0x3F, change `0x27` in the constructor.

## Run
Upload and observe the startup message and uptime counter. If the backlight is on but text is missing, adjust the LCD contrast potentiometer on the backpack.