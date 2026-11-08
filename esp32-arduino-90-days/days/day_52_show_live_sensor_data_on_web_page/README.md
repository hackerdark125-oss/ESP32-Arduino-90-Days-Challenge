# Day 52: Live sensor data on a web page

**Goal:** Display a live ADC reading in a browser, refreshed every second.

## Wiring
Potentiometer outer legs → 3V3 and GND; center wiper → GPIO 34.

## Before upload
Enter Wi-Fi credentials; do not commit real credentials.

## Run
Upload and visit the printed IP address from a device on the same network. The page requests `/reading` once per second and updates the displayed ADC value without a full page reload.

## Concepts
The ESP32 exposes a root dashboard and a plain-text sensor endpoint. JavaScript `fetch()` polls the endpoint. This is a simple local demo; production dashboards should add authentication and secure transport.