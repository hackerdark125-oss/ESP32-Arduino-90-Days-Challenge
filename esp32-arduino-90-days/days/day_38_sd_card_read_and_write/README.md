# Day 38: SD card read and write

**Goal:** Append a line to a microSD card and read the file back.

## Wiring (SPI)
- CS → GPIO 5
- SCK → GPIO 18
- MISO → GPIO 19
- MOSI → GPIO 23
- GND → GND
- Power the SD module as specified by its manufacturer.

Use a 3.3 V-compatible SD breakout. A bare microSD card is not 5 V tolerant.

## Card format
Use a known-good microSD card formatted as FAT16/FAT32 (not exFAT for this basic SD library example).

## Run
Upload and open Serial Monitor at 115200 baud. The sketch appends a line to `/esp32-log.txt`, then prints the file contents.

## Troubleshooting
Check CS pin, SPI wiring, card format and module voltage. Avoid removing the card while writing.