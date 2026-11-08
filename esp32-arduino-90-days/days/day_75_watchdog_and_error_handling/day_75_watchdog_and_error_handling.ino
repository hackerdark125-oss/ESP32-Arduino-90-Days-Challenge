// Day 75: Task watchdog demonstration for Arduino-ESP32 core 3.x.
#include "esp_task_wdt.h"
void setup(){
  Serial.begin(115200);
  esp_task_wdt_config_t config = {
    .timeout_ms = 8000,
    .idle_core_mask = (1 << portNUM_PROCESSORS) - 1,
    .trigger_panic = true
  };
  esp_err_t result=esp_task_wdt_init(&config);
  if(result==ESP_ERR_INVALID_STATE){
    result=esp_task_wdt_reconfigure(&config);
  }
  if(result!=ESP_OK){
    Serial.printf("WDT setup error: %d\n",result);
    return;
  }
  result=esp_task_wdt_add(NULL); // add Arduino loop task
  if(result!=ESP_OK) Serial.printf("WDT add error: %d\n",result);
  else Serial.println("Watchdog enabled. Loop will reset it.");
}
void loop(){
  Serial.println("Healthy loop - resetting watchdog");
  esp_task_wdt_reset();
  delay(1000);
}