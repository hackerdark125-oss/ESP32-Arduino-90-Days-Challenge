// Day 4: Blink an external LED safely.
// GPIO 18 -> 220-330 ohm resistor -> LED anode; LED cathode -> GND.
const int LED_PIN=18;
void setup(){
  Serial.begin(115200);
  pinMode(LED_PIN,OUTPUT);
  digitalWrite(LED_PIN,LOW);
  Serial.println("External LED blink ready.");
}
void loop(){
  digitalWrite(LED_PIN,HIGH);
  delay(500);
  digitalWrite(LED_PIN,LOW);
  delay(500);
}