# Day 48: Parse JSON with ArduinoJson

**Goal:** Convert a JSON text document into values the ESP32 program can use.

## Library
Install **ArduinoJson** (version 7) from Arduino IDE Library Manager.

## Run
Upload and open Serial Monitor at 115200 baud. The sketch parses a sample weather-like JSON document and prints its fields.

## Concepts
`deserializeJson()` parses the document. The `| default` operator supplies fallback values if a field is missing. This lesson uses a local sample string so it can be tested without Wi-Fi or an API key.

## Exercise
Change the sample JSON values, add a new field, and print it. Later, combine this parser with an HTTP response.