// Day 64: Run two FreeRTOS tasks pinned to different ESP32 cores.
void taskOnCore0(void *parameter){
  while(true){ Serial.println("Task running on core 0"); vTaskDelay(pdMS_TO_TICKS(1000)); }
}
void taskOnCore1(void *parameter){
  while(true){ Serial.println("Task running on core 1"); vTaskDelay(pdMS_TO_TICKS(1500)); }
}
void setup(){
  Serial.begin(115200);
  xTaskCreatePinnedToCore(taskOnCore0,"Core0Task",2048,nullptr,1,nullptr,0);
  xTaskCreatePinnedToCore(taskOnCore1,"Core1Task",2048,nullptr,1,nullptr,1);
}
void loop(){ vTaskDelay(pdMS_TO_TICKS(1000)); }