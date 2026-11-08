# Day 36: TFT display with TFT_eSPI

**Goal:** Initialize a SPI TFT display and draw text and shapes.

## Important setup
Install **TFT_eSPI** by Bodmer. Before compiling, configure its `User_Setup.h` for your exact TFT controller, resolution and pins. This example assumes the library is configured correctly; it cannot auto-detect the panel.

Example wiring for an ILI9341 SPI module (verify your board):
- SCK → GPIO 18
- MOSI → GPIO 23
- MISO → GPIO 19 (if used)
- CS → GPIO 27
- DC → GPIO 26
- RST → GPIO 25
- VCC/GND → module specifications

Set matching driver and pin definitions in TFT_eSPI's setup file. Some modules require a separate backlight connection.

## Run
Upload and observe text, a rectangle, a circle and a line. If the screen is blank, first verify the driver, resolution, SPI pins, power and backlight.