# Day 46: NTP time synchronization

**Goal:** Set the ESP32 system clock using a Network Time Protocol server.

## Before upload
Enter your Wi-Fi SSID and password. Do not commit real credentials to the public repository. The example uses India Standard Time (UTC+5:30) and no daylight-saving offset.

## Run
Upload and open Serial Monitor at 115200 baud. After connecting to Wi-Fi, the ESP32 requests time from `pool.ntp.org` and prints the local time.

## Concepts
NTP provides network time; `configTime()` configures the timezone offset and server. The time is available only after a successful network synchronization.