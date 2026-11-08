// Day 28: Ultrasonic parking aid.
// HC-SR04 TRIG -> GPIO 5; ECHO -> GPIO 18 through a 5V-to-3.3V divider.
// LEDs: green 19, yellow 17, red 16 (each with 220-330 ohm resistor).
// Active buzzer module signal -> GPIO 25; verify its input is 3.3V-compatible.
const int TRIG_PIN = 5, ECHO_PIN = 18;
const int GREEN_PIN = 19, YELLOW_PIN = 17, RED_PIN = 16, BUZZER_PIN = 25;
unsigned long lastBeepChange = 0;
bool buzzerOn = false;
float readDistanceCm() {
  digitalWrite(TRIG_PIN, LOW); delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH); delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  unsigned long duration = pulseIn(ECHO_PIN, HIGH, 30000UL);
  if (duration == 0) return -1.0f;
  return duration * 0.0343f / 2.0f;
}
void setIndicators(bool green, bool yellow, bool red) {
  digitalWrite(GREEN_PIN, green);
  digitalWrite(YELLOW_PIN, yellow);
  digitalWrite(RED_PIN, red);
}
void setup() {
  Serial.begin(115200);
  pinMode(TRIG_PIN, OUTPUT); pinMode(ECHO_PIN, INPUT);
  pinMode(GREEN_PIN, OUTPUT); pinMode(YELLOW_PIN, OUTPUT);
  pinMode(RED_PIN, OUTPUT); pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);
}
void loop() {
  float cm = readDistanceCm();
  unsigned long now = millis();
  unsigned long beepInterval = 0;
  if (cm < 0) {
    setIndicators(false, false, false);
    digitalWrite(BUZZER_PIN, LOW);
    Serial.println("No echo");
  } else {
    Serial.print("Distance: "); Serial.print(cm, 1); Serial.println(" cm");
    if (cm > 60) { setIndicators(true, false, false); digitalWrite(BUZZER_PIN, LOW); }
    else if (cm > 30) { setIndicators(false, true, false); digitalWrite(BUZZER_PIN, LOW); }
    else if (cm > 10) { setIndicators(false, false, true); beepInterval = 400; }
    else { setIndicators(false, false, true); beepInterval = 120; }
    if (beepInterval > 0 && now - lastBeepChange >= beepInterval) {
      lastBeepChange = now;
      buzzerOn = !buzzerOn;
      digitalWrite(BUZZER_PIN, buzzerOn ? HIGH : LOW);
    }
    if (beepInterval == 0) { buzzerOn = false; digitalWrite(BUZZER_PIN, LOW); }
  }
  delay(60);
}