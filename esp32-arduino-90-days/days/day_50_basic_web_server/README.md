# Day 50: Basic ESP32 web server

**Goal:** Host a small HTML page on the ESP32 and open it from a device on the same Wi-Fi network.

## Before upload
Enter Wi-Fi credentials in the sketch. Do not publish real credentials.

## Run
Upload and open Serial Monitor at 115200 baud. Copy the printed IP address into a browser on the same local network, using `http://` (for example, `http://192.168.x.x/`).

## Concepts
`WebServer` listens on port 80. The root route returns an HTML response. The main loop must call `server.handleClient()` so requests are processed.

This is a local learning server, not an internet-hardened web service.