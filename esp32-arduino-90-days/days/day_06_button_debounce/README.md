# Day 6: Button debounce

**Goal:** Prevent one physical button press from being read as several presses.

## Parts
- ESP32-WROOM-32
- Push button
- LED and 220–330 Ω resistor
- Breadboard and jumper wires

## Wiring
- Button leg 1 → GPIO 19
- Button leg 2 → GND
- LED anode (long leg) → GPIO 18 through a 220–330 Ω resistor
- LED cathode (short leg) → GND

The button uses the ESP32's internal pull-up, so no external pull-up resistor is needed. The input reads HIGH when released and LOW when pressed.

## Upload
1. Open `day_06_button_debounce.ino` in Arduino IDE.
2. Select your ESP32 board and its COM port.
3. Upload, then open Serial Monitor at **115200 baud**.
4. Press and release the button. The LED should toggle once per press.

## How it works
A mechanical button can rapidly switch between HIGH and LOW while its contacts settle. The sketch waits for the reading to remain stable for 50 ms before accepting a state change.

**Safety:** Use the resistor in series with the LED. Never connect GPIO directly to 5 V.