# Day 45: Access Point mode

**Goal:** Configure the ESP32 to broadcast its own Wi-Fi network.

## Run
Upload and open Serial Monitor at 115200 baud. On a phone or computer, find the network **ESP32-Learning-AP** and connect using the password in the sketch. The ESP32 prints its AP IP address and connected-station count.

## Security
Change the demo password before using this beyond a short local exercise. Use a unique password of at least eight characters. This basic AP does not provide internet access by itself.

## Concepts
Station mode joins an existing Wi-Fi network; access point mode creates a network that nearby clients can join.