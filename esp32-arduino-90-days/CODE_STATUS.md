# 90-Day ESP32 Challenge — Code Preparation Status

**Repository content:** Sketch and lesson README files are present for Days 1–90.

**Target board:** Original ESP32-WROOM-32 development board unless a lesson explicitly states otherwise.

## Important distinction

The code and learning instructions have been prepared in the repository. They have **not** all been compiled, uploaded or verified on physical hardware. Treat each lesson as ready for your own compile-and-test cycle, not as a certified working result.

The `PROGRESS.md` checkboxes are intentionally left unchecked until the corresponding lesson has been completed and verified on the ESP32.

## Compatibility notes
- Some examples use Arduino-ESP32 core 3.x APIs, including LEDC and hardware timers.
- Day 19 requires the ESP32Servo library.
- Days 23, 30–33, 35–36 and 42 require their display/sensor libraries as documented in each README.
- Days 48–49 require ArduinoJson; Day 49 also uses Wi-Fi and an OLED.
- Days 53–54 and 57–59 require the asynchronous server, WebSocket or MQTT libraries named in their READMEs.
- Days 61–63 target Bluetooth-capable original ESP32 hardware; Bluetooth support varies by ESP32 family.
- Days 73–77 include network features. Credentials are placeholders and must be configured locally; do not commit real passwords or tokens.
- Days 78–90 use the SSD1306 OLED capstone hardware and buttons described in the lesson READMEs.

## Before marking a day complete
1. Select the correct board and port in Arduino IDE.
2. Install the libraries named in that day's README.
3. Compile the sketch.
4. Wire the circuit exactly as documented.
5. Upload and test expected behavior.
6. Record any hardware-specific changes or errors.
7. Only then mark the day complete in `PROGRESS.md`.

## Safety
Never connect 5 V signals directly to ESP32 GPIO. Use current-limiting resistors for LEDs, level-shift HC-SR04 ECHO, power servos and relays appropriately, and do not experiment with mains voltage.
