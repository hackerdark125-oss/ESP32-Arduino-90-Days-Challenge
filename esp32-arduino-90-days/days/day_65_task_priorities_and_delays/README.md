# Day 65: Task priorities and delays

**Goal:** Observe how FreeRTOS priorities and blocking delays affect task scheduling.

## Run
Upload and view Serial Monitor at 115200 baud. Two tasks run on core 1 with different priorities and different delay periods.

## Concepts
A higher priority task is selected ahead of a lower priority ready task. `vTaskDelay()` blocks the calling task for a number of ticks, allowing other ready tasks to execute. Priority does not mean a task runs continuously or owns the CPU forever.

## Exercise
Change the delay periods and priorities, then observe the output. Avoid busy loops in FreeRTOS tasks.