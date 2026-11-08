# Day 13: ESP32 pinout and safe pins

**Goal:** Identify useful GPIOs and avoid pins that can cause boot or hardware problems.

## Useful ESP32-WROOM-32 pins
- Common general-purpose GPIOs include 16, 17, 18, 19, 21, 22, 23, 25, 26, 27, 32 and 33. Check your carrier-board pinout.
- GPIO 34, 35, 36 and 39 are input-only and do not have internal pull-up/pull-down resistors.
- GPIO 6–11 are normally connected to SPI flash. Do not use them for ordinary wiring.
- GPIO 0, 2, 5, 12 and 15 are strapping pins; external circuits can affect boot.
- GPIO 1 and 3 are commonly used by USB-UART Serial.

## Electrical rules
- ESP32 GPIO is **3.3 V logic**. Never feed 5 V into a GPIO.
- Use a resistor with each ordinary LED.
- For analog input while Wi-Fi is enabled, prefer ADC1 pins rather than ADC2.
- Board labels and available pins vary. Check the pinout for your exact development board.

## Run
Upload the sketch and open Serial Monitor at 115200 baud. It prints a quick reference and does not change GPIO states.

## Exercise
Choose three GPIOs for LEDs and explain why they are suitable.