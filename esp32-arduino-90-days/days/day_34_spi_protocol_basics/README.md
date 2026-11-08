# Day 34: SPI protocol basics

**Goal:** Understand SPI signals and perform a simple MOSI-to-MISO loopback test.

## Wiring
Connect **GPIO 23 (MOSI) directly to GPIO 19 (MISO)** with a jumper. No external device is required for this loopback test. Default pins used: SCK 18, MISO 19, MOSI 23, CS 5.

## Run
Upload and open Serial Monitor at 115200 baud. The sketch transmits byte 0xA5. With the loopback jumper, it should receive the same byte and print “Loopback OK”.

## Concepts
SPI commonly uses SCK (clock), MOSI (controller-to-peripheral), MISO (peripheral-to-controller) and CS/SS (chip select). A real peripheral must share ground and use compatible logic voltage.

Remove the jumper before connecting an SPI device that drives MISO.