// Day 12: Control an LED using Serial Monitor commands.
// LED: GPIO 18 through a 220-330 ohm resistor to GND.

const int LED_PIN = 18;
String command;

void printHelp() {
  Serial.println("Commands: ON, OFF, TOGGLE, STATUS, HELP");
}

void processCommand(String cmd) {
  cmd.trim();
  cmd.toUpperCase();

  if (cmd == "ON") {
    digitalWrite(LED_PIN, HIGH);
    Serial.println("LED is ON");
  } else if (cmd == "OFF") {
    digitalWrite(LED_PIN, LOW);
    Serial.println("LED is OFF");
  } else if (cmd == "TOGGLE") {
    digitalWrite(LED_PIN, !digitalRead(LED_PIN));
    Serial.println(digitalRead(LED_PIN) ? "LED is ON" : "LED is OFF");
  } else if (cmd == "STATUS") {
    Serial.println(digitalRead(LED_PIN) ? "LED is ON" : "LED is OFF");
  } else if (cmd == "HELP") {
    printHelp();
  } else if (cmd.length() > 0) {
    Serial.println("Unknown command. Type HELP.");
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  Serial.println("Day 12 - Serial LED control");
  printHelp();
}

void loop() {
  if (Serial.available()) {
    command = Serial.readStringUntil('\n');
    processCommand(command);
  }
}