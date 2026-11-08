# Day 53: Asynchronous web server

**Goal:** Serve HTTP routes with ESPAsyncWebServer rather than polling WebServer.handleClient().

## Libraries
Install compatible versions of **ESPAsyncWebServer** and **AsyncTCP** for ESP32. Library forks and versions can differ; use a maintained release compatible with your installed Arduino-ESP32 core.

## Before upload
Set Wi-Fi credentials and keep them out of public commits.

## Run
Upload and open the printed IP address. Visit `/` and `/status`.

## Concepts
The asynchronous server handles requests in the background, so the main `loop()` does not need to call `handleClient()`. Keep callbacks short and avoid blocking operations inside them.