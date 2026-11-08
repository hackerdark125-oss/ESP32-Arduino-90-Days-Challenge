// Day 11: Two independent non-blocking LED tasks.
// LEDs: GPIO 18 and GPIO 19, each with its own 220-330 ohm resistor.

struct BlinkTask {
  int pin;
  unsigned long interval;
  unsigned long lastChange;
  bool state;
};

BlinkTask tasks[] = {
  {18, 300, 0, false},
  {19, 1000, 0, false}
};
const int TASK_COUNT = sizeof(tasks) / sizeof(tasks[0]);

void updateBlinkTask(BlinkTask &task, unsigned long now) {
  if (now - task.lastChange >= task.interval) {
    task.lastChange = now;
    task.state = !task.state;
    digitalWrite(task.pin, task.state ? HIGH : LOW);
  }
}

void setup() {
  Serial.begin(115200);
  for (int i = 0; i < TASK_COUNT; i++) {
    pinMode(tasks[i].pin, OUTPUT);
    digitalWrite(tasks[i].pin, LOW);
    tasks[i].lastChange = millis();
  }
  Serial.println("Day 11 - two independent timed tasks");
}

void loop() {
  const unsigned long now = millis();

  for (int i = 0; i < TASK_COUNT; i++) {
    updateBlinkTask(tasks[i], now);
  }

  // The loop remains free for buttons, sensors and Serial work.
}