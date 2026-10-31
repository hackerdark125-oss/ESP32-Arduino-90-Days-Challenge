# Day 2: Blink the onboard LED

**Phase:** Phase 1: Foundations (Days 1-14)
**Goal:** Use pinMode and digitalWrite

## What I learned
-How pinMode() works and why we use it.

How digitalWrite() turns an LED(HIGH) ON and OFF(LOW).

Understood the difference between HIGH and LOW.

Learned how to use delay() to control the blinking speed.

Got my first hands-on experience uploading and running a program on ESP32 and arduino.

## Parts used
 LED
 
 ESP32 development board (ESP32-WROOM-32)

USB data cable

Windows PC

Arduino IDE

## Wiring / pins
-No external wiring was needed because I used the onboard LED.

LED pin: GPIO 2 (check your board's LED pin)

Board connected to PC through USB.

## Problems and fixes
-Initially, I wasn't sure which GPIO pin controlled the onboard LED.

Checked the board configuration and tested the LED pin.

After uploading the code, I checked whether the LED was blinking correctly.

## Result
Successfully uploaded my first LED blinking program to the ESP32. The onboard LED started blinking ON and OFF at regular intervals.
