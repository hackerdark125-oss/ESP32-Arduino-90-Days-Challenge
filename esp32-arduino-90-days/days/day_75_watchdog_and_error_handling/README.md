# Day 75: Watchdog and error handling

**Goal:** Configure the task watchdog and reset it from the Arduino loop task.

## Compatibility
This example targets Arduino-ESP32 core 3.x and its ESP-IDF task watchdog API.

## Run
Upload and open Serial Monitor at 115200 baud. The loop prints a heartbeat and resets the watchdog once per second.

## Experiment
Temporarily replace the loop delay with a blocking wait longer than the configured 8 seconds (do this only when you can re-upload over USB). The watchdog should trigger a panic/reset if the task fails to feed it.

## Concepts
A watchdog detects tasks that stop yielding or stop making progress. Production firmware should handle errors deliberately and avoid long blocking sections.