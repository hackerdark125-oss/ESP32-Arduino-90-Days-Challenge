# Day 23: DHT22 temperature and humidity

**Goal:** Read temperature and relative humidity from a DHT22 sensor.

## Wiring
For a bare 4-pin DHT22, with the grille facing you: VCC → 3V3, DATA → GPIO 4, NC → not connected, GND → GND. Add a 4.7–10 kΩ pull-up between DATA and 3V3 if your sensor board does not already include one. Check the pinout of your exact module.

## Libraries
Install **DHT sensor library by Adafruit** and **Adafruit Unified Sensor** from Arduino IDE Library Manager.

## Run
Upload and open Serial Monitor at 115200 baud. The sketch reads every 2 seconds and checks for invalid (NaN) results.

**Safety:** Power the sensor from 3.3 V when its data line connects directly to the ESP32.