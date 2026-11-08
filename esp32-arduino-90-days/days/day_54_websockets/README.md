# Day 54: WebSockets

**Goal:** Broadcast live sensor readings over a persistent WebSocket connection.

## Wiring
Potentiometer outer legs → 3V3 and GND; center wiper → GPIO 34.

## Library
Install **WebSockets** by Markus Sattler from Arduino IDE Library Manager.

## Run
Enter Wi-Fi credentials, upload and open Serial Monitor at 115200 baud. The ESP32 prints its WebSocket URL on port 81. Connect a WebSocket client to that address to receive a new ADC value every 500 ms.

## Concepts
HTTP requests normally finish after each response. WebSockets keep a connection open so either side can send messages. This sketch broadcasts text readings to all connected clients.