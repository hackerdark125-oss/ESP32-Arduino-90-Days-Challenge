# Day 19: Servo motor control

**Goal:** Move a hobby servo between positions.

## Parts and wiring
- Standard 3-wire hobby servo
- Servo signal (usually orange/yellow) → GPIO 18
- Servo V+ (usually red) → suitable regulated 5 V supply
- Servo GND (usually brown/black) → supply GND
- ESP32 GND → same supply GND

**Important:** Do not power a servo from the ESP32 3V3 pin. Use a supply rated for the servo's current. Never connect 5 V to an ESP32 GPIO.

## Library
Install **ESP32Servo** from Arduino IDE Library Manager.

## Run
Upload the sketch. The servo sweeps from 0° to 180° and back. Mechanical servos may not safely reach the full range; disconnect the linkage if it binds and reduce the angle range.

## Exercise
Change the step size or use a fixed angle with `myServo.write(angle)`.