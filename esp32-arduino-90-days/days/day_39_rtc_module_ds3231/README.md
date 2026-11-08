# Day 39: RTC module DS3231

**Goal:** Read real date and time from a battery-backed DS3231 clock.

## Wiring
DS3231 SDA → GPIO 21; SCL → GPIO 22; GND → GND; VCC → module-supported voltage. Confirm the breakout's I2C pull-ups are safe for 3.3 V logic.

## Library
Install **RTClib by Adafruit** from Library Manager.

## Run
Upload and open Serial Monitor at 115200 baud. If the RTC reports lost power, the sketch sets it to the computer's sketch compile time. That is not necessarily the exact current time; for accurate setting, adjust it explicitly or synchronize with a trusted time source.

## Concepts
The DS3231 keeps time using its backup coin cell when the ESP32 is off. Check battery condition if time resets.