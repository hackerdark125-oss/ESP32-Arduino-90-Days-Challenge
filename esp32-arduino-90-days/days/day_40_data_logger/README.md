# Day 40: Timestamped data logger

**Goal:** Save periodic sensor readings with RTC timestamps to a CSV file on microSD.

## Wiring
- DS3231: SDA 21, SCL 22, GND and supported VCC.
- SD module: CS 5, SCK 18, MISO 19, MOSI 23, GND and supported supply.
- Potentiometer: outer legs 3V3/GND; wiper GPIO 34.

Use 3.3 V-compatible logic. Check module power requirements and avoid unsafe pull-up voltages.

## Libraries
Install Adafruit RTClib. The SD and SPI libraries are included with the ESP32 Arduino core.

## Run
Upload. Every five seconds the sketch appends a timestamp and ADC value to `/readings.csv`. Open Serial Monitor at 115200 baud to see new rows.

## Notes
If the RTC has lost power, it is set to sketch compile time. Set it accurately before using the log for real measurements. Always close the file after writing, as this sketch does.