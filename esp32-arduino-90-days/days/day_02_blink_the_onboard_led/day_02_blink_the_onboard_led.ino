// Day 2: Blink the onboard LED.
// Many ESP32 DevKit boards use GPIO 2, but the LED pin varies by board.
#ifndef LED_BUILTIN
#define LED_BUILTIN 2
#endif
const int LED_PIN = LED_BUILTIN;
void setup(){
  pinMode(LED_PIN,OUTPUT);
}
void loop(){
  digitalWrite(LED_PIN,HIGH);
  delay(500);
  digitalWrite(LED_PIN,LOW);
  delay(500);
}