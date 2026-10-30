# ESP32 WROOM-32 Pin Notes

- **Input-only pins:** GPIO 34, 35, 36, 39 (no output, no internal pull-ups)
- **Avoid for general use:** GPIO 6-11 (connected to flash)
- **Strapping pins (careful at boot):** GPIO 0, 2, 5, 12, 15
- **ADC2 pins** do not work while WiFi is active; use ADC1 (GPIO 32-39) with WiFi
- **Default I2C:** SDA = GPIO 21, SCL = GPIO 22
- **Default SPI (VSPI):** MOSI 23, MISO 19, SCK 18, SS 5
- **Logic level:** 3.3 V only. Do not feed 5 V into GPIO pins.

Add your own board's labeled pinout image here.
