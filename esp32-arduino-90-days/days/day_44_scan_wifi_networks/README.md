# Day 44: Scan Wi-Fi networks

**Goal:** Scan visible 2.4 GHz Wi-Fi networks and print SSID and signal strength.

## Run
Upload and open Serial Monitor at 115200 baud. The ESP32 lists detected network names, RSSI in dBm and whether the network is open or secured.

## Concepts
RSSI is a rough signal-strength measurement; values closer to zero are stronger. The ESP32-WROOM-32 scans 2.4 GHz networks. Network visibility depends on region, channel and signal conditions.

**Privacy:** Do not publish scans containing nearby people's network names or other identifying information.