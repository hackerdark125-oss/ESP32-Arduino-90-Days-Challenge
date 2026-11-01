// Day 4: External LED and resistor
// Goal: Wire an LED on a breadboard safely
int Ledpin=10;
void setup() {
  pinMode(Ledpin,OUTPUT);
  Serial.begin(9600);
  // TODO: setup code
}

void loop() {
  digitalWrite(Ledpin,HIGH);
  // TODO: main code
}
