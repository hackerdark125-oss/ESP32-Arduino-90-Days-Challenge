# Day 57: MQTT basics

**Goal:** Connect to an MQTT broker, subscribe to a topic and publish a test message.

## Library
Install **PubSubClient** by Nick O'Leary.

## Before upload
Set Wi-Fi credentials and replace the topic suffix with a unique random label. Never publish private information. The example uses the public Mosquitto test broker on unencrypted port 1883.

## Run
Upload and open Serial Monitor at 115200 baud. The ESP32 publishes a message every five seconds and prints messages received on the subscribed topic. To test two-way messaging, use a separate MQTT client to publish to the same topic.

## Security
The public test broker is shared and unencrypted. Do not use it for production, secrets or sensitive data. Production systems need authentication, TLS and access controls.