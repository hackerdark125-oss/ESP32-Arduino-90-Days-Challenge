const int buttonPin = 2;
const int ledPin = 13;

int ledState = LOW;
int buttonState = HIGH;
int lastButtonReading = HIGH;

unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);

  digitalWrite(ledPin, ledState);
}

void loop() {
  int reading = digitalRead(buttonPin);

  if (reading != lastButtonReading) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {

    if (reading != buttonState) {
      buttonState = reading;

      if (buttonState == LOW) {
        ledState = !ledState;
        digitalWrite(ledPin, ledState);
      }
    }
  }

  lastButtonReading = reading;
}
