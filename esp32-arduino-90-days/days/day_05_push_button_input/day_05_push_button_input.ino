// Day 5: Read a push button with the ESP32 internal pull-up.
// Button connects GPIO 19 to GND. LED on GPIO 18 through 220-330 ohm resistor.
const int BUTTON_PIN=19;
const int LED_PIN=18;
void setup(){
  Serial.begin(115200);
  pinMode(BUTTON_PIN,INPUT_PULLUP);
  pinMode(LED_PIN,OUTPUT);
}
void loop(){
  bool pressed=(digitalRead(BUTTON_PIN)==LOW);
  digitalWrite(LED_PIN,pressed?HIGH:LOW);
  if(pressed) Serial.println("Button pressed");
  delay(50);
}