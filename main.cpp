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



// new project task

void Task_Led(void *pvparameters){
  pinMode(2,OUTPUT);
  while(1){
    digitalWrite(2,HIGH);
    vTaskDelay(500 / portTICK_PERIOD_MS);
    digitalWrite(2,LOW);
    vTaskDelay(500 / portTICK_PERIOD_MS);
  }
}

void Task_Serial(void *pvParameters){
  while(1){
    Serial.println("Serial Task : System running");
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}

void Task_Button(void *pvParameters){
  pinMode(4, INPUT_PULLUP); 
  while(1){
    if(digitalRead(4) == LOW){
      Serial.println("Button pressed");
      while(digitalRead(4) == LOW) {
        vTaskDelay(10 / portTICK_PERIOD_MS); \
      }
    }
    vTaskDelay(50 / portTICK_PERIOD_MS);
  }
}

void setup(){
  Serial.begin(115200);
  xTaskCreate(Task_Led,"led task",1024,NULL,1,NULL);
  xTaskCreate(Task_Serial,"Serial task",2048,NULL,1,NULL);
  xTaskCreate(Task_Button,"button task",1024,NULL,1,NULL);
}
void loop(){

}
