// Day 69: Deep sleep with timer and external GPIO wake.
// Button: external 10k pull-up GPIO 33 to 3V3; button GPIO 33 to GND.
#include "esp_sleep.h"
const gpio_num_t WAKE_BUTTON = GPIO_NUM_33;
void setup(){
  Serial.begin(115200);
  delay(500);
  Serial.print("Wakeup cause: ");
  Serial.println((int)esp_sleep_get_wakeup_cause());
  pinMode((int)WAKE_BUTTON, INPUT);
  esp_sleep_enable_timer_wakeup(10ULL * 1000000ULL);
  esp_sleep_enable_ext0_wakeup(WAKE_BUTTON, 0);
  Serial.println("Entering deep sleep. Timer: 10 seconds; button: GPIO33 LOW.");
  delay(500);
  Serial.flush();
  esp_deep_sleep_start();
}
void loop(){}