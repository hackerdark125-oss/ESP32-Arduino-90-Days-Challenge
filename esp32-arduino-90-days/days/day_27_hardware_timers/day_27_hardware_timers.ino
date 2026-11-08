// Day 27: ESP32 hardware timer using Arduino-ESP32 core 3.x.
#include "esp_timer.h"
hw_timer_t *timer = nullptr;
volatile uint32_t timerTicks = 0;
void ARDUINO_ISR_ATTR onTimer() {
  timerTicks++;
}
void setup() {
  Serial.begin(115200);
  timer = timerBegin(1000000); // timer tick frequency: 1 MHz
  if (timer == nullptr) {
    Serial.println("Could not create hardware timer.");
    while (true) delay(1000);
  }
  timerAttachInterrupt(timer, &onTimer);
  timerAlarm(timer, 1000000, true, 0); // 1 second, auto-reload
  Serial.println("Hardware timer started.");
}
void loop() {
  static uint32_t lastReported = 0;
  uint32_t ticks;
  noInterrupts();
  ticks = timerTicks;
  interrupts();
  if (ticks != lastReported) {
    lastReported = ticks;
    Serial.print("Timer ticks: ");
    Serial.println(ticks);
  }
}