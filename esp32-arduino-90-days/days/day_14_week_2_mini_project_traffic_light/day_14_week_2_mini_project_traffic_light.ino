// Day 14: Traffic light using a millis()-based state machine.
// Red GPIO 16, Yellow GPIO 17, Green GPIO 18.
// Each LED needs its own 220-330 ohm series resistor.
const int RED_PIN = 16;
const int YELLOW_PIN = 17;
const int GREEN_PIN = 18;
enum TrafficState { RED, GREEN, YELLOW };
TrafficState state = RED;
unsigned long stateStartedAt = 0;
const unsigned long RED_MS = 4000;
const unsigned long GREEN_MS = 4000;
const unsigned long YELLOW_MS = 1500;

void setLights(bool redOn, bool yellowOn, bool greenOn) {
  digitalWrite(RED_PIN, redOn ? HIGH : LOW);
  digitalWrite(YELLOW_PIN, yellowOn ? HIGH : LOW);
  digitalWrite(GREEN_PIN, greenOn ? HIGH : LOW);
}
void enterState(TrafficState nextState, unsigned long now) {
  state = nextState;
  stateStartedAt = now;
  switch (state) {
    case RED: setLights(true, false, false); Serial.println("RED"); break;
    case GREEN: setLights(false, false, true); Serial.println("GREEN"); break;
    case YELLOW: setLights(false, true, false); Serial.println("YELLOW"); break;
  }
}
void setup() {
  Serial.begin(115200);
  pinMode(RED_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  enterState(RED, millis());
  Serial.println("Day 14 - traffic light state machine");
}
void loop() {
  const unsigned long now = millis();
  const unsigned long elapsed = now - stateStartedAt;
  if (state == RED && elapsed >= RED_MS) enterState(GREEN, now);
  else if (state == GREEN && elapsed >= GREEN_MS) enterState(YELLOW, now);
  else if (state == YELLOW && elapsed >= YELLOW_MS) enterState(RED, now);
}