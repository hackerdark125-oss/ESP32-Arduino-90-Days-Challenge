# Day 64: Dual core and FreeRTOS tasks

**Goal:** Run two independent FreeRTOS tasks pinned to the ESP32's two cores.

## Run
Upload and open Serial Monitor at 115200 baud. Messages from each task should appear at different intervals.

## Concepts
`xTaskCreatePinnedToCore()` creates a task and selects its core. `vTaskDelay()` yields the CPU so other tasks can run. Both tasks use Serial here only for a simple demonstration; shared peripherals need synchronization.

## Notes
This example targets the dual-core original ESP32-WROOM-32. Other ESP32 variants may have one core or different task behavior.