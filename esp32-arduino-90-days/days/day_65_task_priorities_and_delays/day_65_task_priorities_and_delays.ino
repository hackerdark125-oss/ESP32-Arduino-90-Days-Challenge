// Day 65: Demonstrate FreeRTOS task priorities and delays.
void lowPriorityTask(void *arg){
  while(true){
    Serial.println("Low priority task");
    vTaskDelay(pdMS_TO_TICKS(1000));
  }
}
void higherPriorityTask(void *arg){
  while(true){
    Serial.println("Higher priority task");
    vTaskDelay(pdMS_TO_TICKS(1500));
  }
}
void setup(){
  Serial.begin(115200);
  xTaskCreatePinnedToCore(lowPriorityTask,"LowTask",2048,nullptr,1,nullptr,1);
  xTaskCreatePinnedToCore(higherPriorityTask,"HighTask",2048,nullptr,2,nullptr,1);
}
void loop(){ vTaskDelay(pdMS_TO_TICKS(1000)); }