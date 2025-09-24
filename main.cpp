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
// add queuehandle 

QueueHandle_t buttonQueue;

void Task_Button(void *pvParameters){

  pinMode(4, INPUT_PULLUP); // button on gpio4, press = lowByte(x);
  int msg = 1;
  while(1){
    if(digitalRead(4) == LOW){
      xQueueSend(buttonQueue,&msg,portMAX_DELAY);
      Serial.println("Button pressed and message sent to queue");
      vTaskDelay(200 / portTICK_PERIOD_MS);
    }
    vTaskDelay(50 / portTICK_PERIOD_MS);
  }

}

void Task_Led(void *pvParameters){
  pinMode(2,OUTPUT);
  int received;
  while(1){
    if(xQueueReceive(buttonQueue,&received,portMAX_DELAY)== pdPASS){
      if(received == 1){
        digitalWrite(2,HIGH);
        vTaskDelay(500 / portTICK_PERIOD_MS);
        digitalWrite(2, !digitalRead(2));
        digitalWrite(2,LOW);
        vTaskDelay(500 / portTICK_PERIOD_MS);
      }
    }
  }
}


void Task_serial(void *pvParameters){
  while(1){
    Serial.println("System running");
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}
void setup(){
  Serial.begin(115200);
  buttonQueue = xQueueCreate(5,sizeof(int));
  xTaskCreate(Task_Button,"button task",1000,NULL,1,NULL);
  xTaskCreate(Task_Led,"led task",1000,NULL,1,NULL);
  xTaskCreate(Task_serial,"serial task",2000,NULL,1,NULL);

}
void loop(){

}

// add semaphore
SemaphoreHandle_t xButtonSemaphore;

void Task_Led(void *pvParamerters){
  pinMode(2,OUTPUT);
  while(1){
    if(xSemaphoreTake(xButtonSemaphore,portMAX_DELAY)==pdTRUE){
      digitalWrite(2, !digitalRead(2));
      Serial.println("Led is started by button press");

    }
  }
}

void Task_Button(void *pvParameters){
  pinMode(4, INPUT_PULLDOWN);
  while(1){
    if(digitalRead(4) == LOW){
      xSemaphoreGive(xButtonSemaphore);
      vTaskDelay(200 / portTICK_PERIOD_MS);
    }
    vTaskDelay(50 / portTICK_PERIOD_MS);
  }
}
void setup(){
  Serial.begin(115200);
  xButtonSemaphore = xSemaphoreCreateBinary();
  xTaskCreate(Task_Button,"button task",1000,NULL,1,NULL);
  xTaskCreate(Task_Led,"led task",1000,NULL,1,NULL);
}

void loop(){

}


// counting semaphore
#define NUM_TASKS 5
const int ledpins[NUM_TASKS] = {2,4,5,18,19};
SemaphoreHandle_t countingSem;

void worker_task(void *pvParameters){
  int id = (int)(intptr_t)pvParameters;
  pinMode(ledpins[id],OUTPUT);
  for(;;){
    Serial.printf("task %d: waiting for resource...\n",id);
    if(xSemaphoreTake(countingSem,portMAX_DELAY)==pdTRUE){
      Serial.printf("task %d: accquired resorce - endtring id\n",id);
      for(int i = 0; i < 3; i++){
        digitalWrite(ledpins[id],HIGH);
        vTaskDelay(200 / portTICK_PERIOD_MS);
        digitalWrite(ledpins[id],LOW);
        vTaskDelay(200 / portTICK_PERIOD_MS);
      }
      Serial.printf("task %d: releasing resource\n",id);
      xSemaphoreGive(countingSem);
   

    }
    vTaskDelay((1000 + id * 200) / portTICK_PERIOD_MS);
  }
}
void setup(){
  Serial.begin(115200);
  countingSem = xSemaphoreCreateCounting(2,2);
  for(int  i = 0; i < NUM_TASKS; i++){
    xTaskCreate(worker_task,"worker",1000,(void *)(intptr_t)i,1,NULL);
  }
 
}
void loop(){
  
}


SemaphoreHandle_t serialMutex;

void Task_printer(void *pvParameters) {
  int id = (int)(intptr_t)pvParameters;

  for (;;) {
    if (xSemaphoreTake(serialMutex, portMAX_DELAY) == pdTRUE) {
      Serial.printf("[task %d] start printing .....\n", id);
      Serial.printf("[task %d] line a\n", id);
      Serial.printf("[task %d] line b\n", id);
      Serial.printf("[task %d] end printing...\n\n", id);
      xSemaphoreGive(serialMutex);
    }

  
    vTaskDelay((500 + id * 200) / portTICK_PERIOD_MS);
  }
}

void setup() {
  Serial.begin(115200);
  delay(1000); 

 
  serialMutex = xSemaphoreCreateMutex();
  if (serialMutex == NULL) {
    Serial.println("Mutex creation failed!");
    while (1) { vTaskDelay(1000 / portTICK_PERIOD_MS); }
  }


  xTaskCreate(Task_printer, "Task1", 2048, (void *)(intptr_t)1, 2, NULL);
  xTaskCreate(Task_printer, "Task2", 2048, (void *)(intptr_t)2, 1, NULL);
}

void loop() {

}
