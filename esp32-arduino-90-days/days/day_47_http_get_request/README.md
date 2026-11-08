# Day 47: HTTP GET request

**Goal:** Request a public test endpoint from the ESP32 and print its response.

## Before upload
Set Wi-Fi credentials in the sketch. Never commit real credentials to a public repository.

## Libraries
`WiFi.h` and `HTTPClient.h` are included with the ESP32 Arduino core.

## Run
Upload and open Serial Monitor at 115200 baud. The ESP32 requests `http://httpbin.org/get`, prints the HTTP status code and response body, then closes the connection.

## Security
This lesson uses plain HTTP only for a non-sensitive public test request. Do not transmit passwords, tokens or personal data over plain HTTP. For real services, use HTTPS with certificate validation.