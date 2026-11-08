// Day 41: Read a rotary encoder and its push button.
const int ENC_A = 32;
const int ENC_B = 33;
const int ENC_BUTTON = 25;
int lastA;
long position = 0;
int lastButton = HIGH;
unsigned long lastButtonTime = 0;
void setup() {
  Serial.begin(115200);
  pinMode(ENC_A, INPUT_PULLUP);
  pinMode(ENC_B, INPUT_PULLUP);
  pinMode(ENC_BUTTON, INPUT_PULLUP);
  lastA = digitalRead(ENC_A);
  Serial.println("Rotate encoder; press its switch.");
}
void loop() {
  int a = digitalRead(ENC_A);
  if (a != lastA && a == LOW) {
    position += (digitalRead(ENC_B) == HIGH) ? 1 : -1;
    Serial.print("Position: "); Serial.println(position);
  }
  lastA = a;
  int button = digitalRead(ENC_BUTTON);
  if (button == LOW && lastButton == HIGH && millis() - lastButtonTime > 200) {
    lastButtonTime = millis();
    Serial.println("Encoder button pressed");
  }
  lastButton = button;
}