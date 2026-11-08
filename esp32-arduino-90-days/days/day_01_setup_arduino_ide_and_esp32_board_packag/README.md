# Day 1: Setup Arduino IDE and ESP32 board package

**Goal:** Install the Arduino IDE, add ESP32 board support and upload your first sketch.

## Setup
1. Install Arduino IDE 2.x.
2. Open Preferences and add Espressif's ESP32 Boards Manager URL from the official Espressif Arduino-ESP32 installation guide.
3. Open Boards Manager, search for **esp32 by Espressif Systems**, and install it.
4. Connect the ESP32-WROOM-32 development board with a USB data cable.
5. Select the correct ESP32 board and COM port.

## Run
Open this sketch, click Upload, then open Serial Monitor at **115200 baud**. You should see the chip model, CPU frequency and a counter.

## Troubleshooting
- Try another USB data cable and USB port.
- Install the USB-UART driver required by your development board.
- Close Serial Monitor before uploading if the port is busy.
- If upload fails at “Connecting…”, hold BOOT while upload starts, then release when writing begins.

Do not select a board based only on the module name; choose the matching development-board entry.