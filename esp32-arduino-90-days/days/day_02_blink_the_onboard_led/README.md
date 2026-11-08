# Day 2: Blink the onboard LED

**Goal:** Use `pinMode()` and `digitalWrite()` to blink the board's built-in LED.

## Run
Select your ESP32 board and COM port, upload the sketch, and observe the LED blinking every half second.

## Pin note
Many classic ESP32 DevKit boards connect the onboard LED to GPIO 2, but this is not universal. Check the pinout/schematic for your exact board. If your board has no onboard LED, connect an external LED to a suitable GPIO through a 220–330 Ω resistor and change `LED_PIN`.

GPIO 2 is a strapping pin on the classic ESP32. Do not attach external circuitry that forces an unsafe level during boot.