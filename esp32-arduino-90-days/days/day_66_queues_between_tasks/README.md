# Day 66: Queues between tasks

**Goal:** Pass data from one FreeRTOS task to another using a queue.

## Run
Upload and open Serial Monitor at 115200 baud. The producer generates sample values; the consumer receives and prints them.

## Concepts
A queue copies data between tasks and provides synchronization. `xQueueSend()` adds an item, while `xQueueReceive()` removes one. The queue has a capacity of five integers.

## Exercise
Replace the generated value with `analogRead(34)` after connecting a potentiometer to GPIO 34.