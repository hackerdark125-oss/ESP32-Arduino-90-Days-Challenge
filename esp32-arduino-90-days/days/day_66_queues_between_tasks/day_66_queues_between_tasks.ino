// Day 66: Pass sensor-like values safely between FreeRTOS tasks.
QueueHandle_t readingQueue;
void producerTask(void *arg){
  int value=0;
  while(true){
    value=(value+137)%4096;
    xQueueSend(readingQueue,&value,portMAX_DELAY);
    vTaskDelay(pdMS_TO_TICKS(500));
  }
}
void consumerTask(void *arg){
  int received;
  while(true){
    if(xQueueReceive(readingQueue,&received,portMAX_DELAY)==pdTRUE){
      Serial.print("Queue value: "); Serial.println(received);
    }
  }
}
void setup(){
  Serial.begin(115200);
  readingQueue=xQueueCreate(5,sizeof(int));
  if(readingQueue==nullptr){Serial.println("Queue creation failed");return;}
  xTaskCreate(producerTask,"Producer",2048,nullptr,1,nullptr);
  xTaskCreate(consumerTask,"Consumer",2048,nullptr,1,nullptr);
}
void loop(){vTaskDelay(pdMS_TO_TICKS(1000));}