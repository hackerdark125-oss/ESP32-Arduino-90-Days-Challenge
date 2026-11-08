# Day 43: Connect to Wi-Fi

**Goal:** Connect the ESP32 to a Wi-Fi network in station mode.

## Before upload
Edit `WIFI_SSID` and `WIFI_PASSWORD` in the sketch. Do not commit real Wi-Fi credentials to a public repository. Use a temporary test network or keep credentials in a private, ignored secrets file.

## Run
Upload and open Serial Monitor at 115200 baud. On success, the ESP32 prints its local IP address.

## Notes
The classic ESP32-WROOM-32 supports 2.4 GHz Wi-Fi, not 5 GHz-only networks. Use a 2.4 GHz SSID and keep the board within range. The sketch retries if the connection drops.