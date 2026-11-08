# Day 49: Weather station mini project

**Goal:** Fetch current weather values from Open-Meteo and show them on an SSD1306 OLED.

## Before upload
Set your Wi-Fi credentials. The example requests a sample coordinate near Dehradun; edit latitude/longitude in the URL for your chosen location.

## Libraries and wiring
Install ArduinoJson v7, Adafruit SSD1306 and Adafruit GFX. OLED SDA 21, SCL 22, GND and supported VCC.

## Run
Upload and open Serial Monitor at 115200 baud. The OLED should show temperature and humidity from the Open-Meteo current-weather response.

## TLS warning
For a short learning demonstration, this sketch calls `setInsecure()`, which disables HTTPS certificate verification. This is **not safe for production**. Real projects must validate the server certificate using a maintained CA certificate. Do not send secrets through this insecure connection.