// Day 19: Sweep a hobby servo using ESP32Servo.
// Signal -> GPIO 18. Power servo from a suitable external 5V supply.
// Connect external supply GND to ESP32 GND. Do not power a loaded servo from 3V3.
#include <ESP32Servo.h>
Servo myServo;
const int SERVO_PIN = 18;
void setup() {
  Serial.begin(115200);
  myServo.setPeriodHertz(50);
  myServo.attach(SERVO_PIN, 500, 2400);
  Serial.println("Day 19 - servo sweep");
}
void loop() {
  for (int angle = 0; angle <= 180; angle += 2) {
    myServo.write(angle);
    delay(20);
  }
  for (int angle = 180; angle >= 0; angle -= 2) {
    myServo.write(angle);
    delay(20);
  }
}