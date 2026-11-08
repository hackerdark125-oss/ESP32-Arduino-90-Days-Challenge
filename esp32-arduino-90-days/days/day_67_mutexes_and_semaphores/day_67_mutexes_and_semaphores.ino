// Day 67: Protect a shared counter with a FreeRTOS mutex.
SemaphoreHandle_t counterMutex;
int sharedCounter=0;
void workerTask(void *arg){
  const char *name=(const char*)arg;
  while(true){
    if(xSemaphoreTake(counterMutex,portMAX_DELAY)==pdTRUE){
      sharedCounter++;
      Serial.print(name); Serial.print(" updated counter to ");
      Serial.println(sharedCounter);
      xSemaphoreGive(counterMutex);
    }
    vTaskDelay(pdMS_TO_TICKS(700));
  }
}
void setup(){
  Serial.begin(115200);
  counterMutex=xSemaphoreCreateMutex();
  if(counterMutex==nullptr){Serial.println("Mutex creation failed");return;}
  xTaskCreate(workerTask,"WorkerA",2048,(void*)"A",1,nullptr);
  xTaskCreate(workerTask,"WorkerB",2048,(void*)"B",1,nullptr);
}
void loop(){vTaskDelay(pdMS_TO_TICKS(1000));}