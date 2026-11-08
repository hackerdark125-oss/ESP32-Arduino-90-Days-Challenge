// Day 21: Potentiometer-controlled LED brightness.
// Pot wiper -> GPIO 34; outer legs -> 3V3 and GND.
// LED anode -> resistor -> GPIO 18; cathode -> GND.
const int POT_PIN = 34;
const int LED_PIN = 18;
void setup() {
  Serial.begin(115200);
  analogReadResolution(12);
  if (!ledcAttach(LED_PIN, 5000, 8)) {
    Serial.println("LEDC attach failed.");
    while (true) delay(1000);
  }
}
void loop() {
  int raw = analogRead(POT_PIN);
  int duty = map(raw, 0, 4095, 0, 255);
  ledcWrite(LED_PIN, duty);
  Serial.print("ADC="); Serial.print(raw);
  Serial.print(" duty="); Serial.println(duty);
  delay(50);
}