// Day 25: PIR motion sensor.
// PIR OUT -> GPIO 27; PIR VCC/GND according to module rating.
// LED GPIO 18 through a 220-330 ohm resistor to GND.
const int PIR_PIN = 27;
const int LED_PIN = 18;
int lastMotion = LOW;
void setup() {
  Serial.begin(115200);
  pinMode(PIR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  Serial.println("PIR warming up; allow the sensor to stabilize.");
}
void loop() {
  int motion = digitalRead(PIR_PIN);
  digitalWrite(LED_PIN, motion ? HIGH : LOW);
  if (motion != lastMotion) {
    Serial.println(motion ? "Motion detected" : "No motion");
    lastMotion = motion;
  }
  delay(50);
}