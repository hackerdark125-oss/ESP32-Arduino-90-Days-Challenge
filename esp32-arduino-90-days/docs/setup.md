# Setup Guide

1. Install Arduino IDE 2.x from arduino.cc.
2. Open File > Preferences and add this to "Additional boards manager URLs":
   `https://espressif.github.io/arduino-esp32/package_esp32_index.json`
3. Tools > Board > Boards Manager, search "esp32" and install the package by Espressif Systems.
4. Select board: **ESP32 Dev Module** (works for most WROOM-32 DevKits).
5. Plug in via USB, choose the port under Tools > Port.
6. If the port does not appear, install the CP210x or CH340 USB driver.
7. If upload hangs on "Connecting...", hold the BOOT button until upload starts.
8. Set Serial Monitor baud rate to 115200.

## Sketch naming
The Arduino IDE needs the sketch folder name to match the `.ino` file name. Each day's folder already follows this.
