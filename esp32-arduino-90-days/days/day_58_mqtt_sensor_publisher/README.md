# Day 58: MQTT sensor publisher

**Goal:** Send a potentiometer ADC value to an MQTT topic every five seconds.

## Wiring
Potentiometer outer legs → 3V3 and GND; wiper → GPIO 34.

## Library and setup
Install PubSubClient. Enter Wi-Fi credentials and change the topic to a unique label.

## Run
Upload and open Serial Monitor at 115200 baud. Subscribe to the topic using an MQTT client to see the readings.

## Security
The sketch uses the shared public test broker over unencrypted MQTT. Use only non-sensitive demo values. Production systems require broker authentication, TLS and topic access controls.