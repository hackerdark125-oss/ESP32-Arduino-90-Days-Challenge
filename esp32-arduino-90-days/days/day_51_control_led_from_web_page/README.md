# Day 51: Control an LED from a web page

**Goal:** Turn an ESP32-connected LED on and off from a browser on the same local network.

## Wiring
GPIO 18 → 220–330 Ω resistor → LED anode; LED cathode → GND.

## Before upload
Enter Wi-Fi credentials. Do not commit real credentials to the public repository.

## Run
Upload and open Serial Monitor at 115200 baud. Visit the printed IP address from a phone/computer connected to the same Wi-Fi. Use the ON and OFF buttons.

## Concepts
The web server handles `/on` and `/off` routes, changes the GPIO output and returns the updated page.

**Safety:** This demo controls only a low-voltage LED. Do not use the example to switch mains voltage or dangerous equipment.