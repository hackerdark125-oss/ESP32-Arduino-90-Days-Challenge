// Day 60: Demonstrate a relay module with a low-voltage indicator only.
// Relay IN -> GPIO 26. Relay VCC/GND per module datasheet.
// Never connect mains voltage for this learning exercise.
const int RELAY_PIN=26;
const int BUTTON_PIN=27;
const bool RELAY_ACTIVE_LOW=true; // change only after checking your module
bool relayOn=false;
int lastButton=HIGH;
unsigned long lastPress=0;
void setRelay(bool on){
  relayOn=on;
  digitalWrite(RELAY_PIN, (on ^ RELAY_ACTIVE_LOW) ? HIGH : LOW);
  Serial.println(on ? "Relay energized" : "Relay released");
}
void setup(){
  Serial.begin(115200);
  pinMode(RELAY_PIN,OUTPUT);
  pinMode(BUTTON_PIN,INPUT_PULLUP);
  setRelay(false);
}
void loop(){
  int b=digitalRead(BUTTON_PIN);
  if(b==LOW && lastButton==HIGH && millis()-lastPress>200){
    lastPress=millis(); setRelay(!relayOn);
  }
  lastButton=b;
}