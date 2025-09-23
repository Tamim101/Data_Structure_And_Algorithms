#include <Arduino.h>

void Task_Low(void *pvParameter){
  while(1){
    Serial.println("LOW PRIORITY TASK IS RUNNING...............");
    vTaskDelay(2000 / portTICK_PERIOD_MS);
  }
}
void Task_High(void *pvParameters){
  while(1){
    Serial.println("HIGH PRIORITY TASK RUNNING.............");
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}
void Task3(void *pvParameter){
  Serial.println("task 3 running<<<>>>><<<>>>");
  vTaskDelay(1000 / portTICK_PERIOD_MS);
}
void setup(){
  Serial.begin(115200);
  xTaskCreate(Task_Low,
    "Tasklow",
    1000,
    NULL,
    1,
    NULL
  );

  xTaskCreate(Task_High, "Taskhigh",1000,NULL,1,NULL);
  xTaskCreate(Task3,"task3",1000,NULL,1,NULL);
}

void loop(){

}