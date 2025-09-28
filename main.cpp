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

#include <Arduino.h>
#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"

EventGroupHandle_t systemEventGroup;

#define SENSOR_READY   (1 << 0)  // bit 0
#define WIFI_READY     (1 << 1)  // bit 1

void Task_Sensor(void *pvParameters) {
  vTaskDelay(2000 / portTICK_PERIOD_MS); 
  Serial.println("Sensor initialized ");
  xEventGroupSetBits(systemEventGroup, SENSOR_READY);
  vTaskDelete(NULL);
}

void Task_WiFi(void *pvParameters) {
  vTaskDelay(4000 / portTICK_PERIOD_MS); 
  Serial.println("Wi-Fi connected ");
  xEventGroupSetBits(systemEventGroup, WIFI_READY);
  vTaskDelete(NULL);
}

void Task_Coordinator(void *pvParameters) {
  Serial.println("Coordinator waiting for Sensor + Wi-Fi...");

  xEventGroupWaitBits(
    systemEventGroup,
    SENSOR_READY | WIFI_READY, 
    pdFALSE,                   
    pdTRUE,                    
    portMAX_DELAY            
  );

  Serial.println("All systems ready Starting main application!");
  vTaskDelete(NULL);
}

void setup() {
  Serial.begin(115200);
  vTaskDelay(1000 / portTICK_PERIOD_MS);
  systemEventGroup = xEventGroupCreate();

  xTaskCreate(Task_Sensor, "Sensor", 2048, NULL, 1, NULL);
  xTaskCreate(Task_WiFi, "WiFi", 2048, NULL, 1, NULL);
  xTaskCreate(Task_Coordinator, "Coordinator", 2048, NULL, 2, NULL);
}

void loop() {

}

TaskHandle_t ledTaskHandle = NULL;
void Task_button(void *pvParameters){
  pinMode(4,INPUT_PULLUP);
  while(1){
    if(digitalRead(4) == LOW){
      xTaskNotifyGive(ledTaskHandle);
      vTaskDelay(300 / portTICK_PERIOD_MS);
    }
    vTaskDelay(50 / portTICK_PERIOD_MS);
  }
}

void Task_led(void *pvParameters){
  pinMode(2,INPUT_PULLUP);
    while(1){
      // int count = ulTaskNotifyTake(pdTRUE,portMAX_DELAY);
      // if(count > 0){
      //   static int press_count = 0;
      //   press_count++;
      //   if (press_count == 1) {
      //     Serial.println("OK, push this button 2nd time");
      // }
      //   else if (press_count == 2) {
      //    Serial.println("Good, now push the button final time");
      // }
      //   else if (press_count == 3) {
      //   Serial.println("Great! Starting system now...");
      ulTaskNotifyTake(pdTRUE,portMAX_DELAY);
      ulTaskNotifyTake(pdTRUE,portMAX_DELAY);
      ulTaskNotifyTake(pdTRUE,portMAX_DELAY);
      digitalWrite(2, !digitalRead(2));
      Serial.println("[led task], led on after 3 button presses");

    }
  }
  
void setup(){
  Serial.begin(115200);
  delay(1000);
  xTaskCreate(Task_led,"led task",1000,NULL,1,&ledTaskHandle);
  xTaskCreate(Task_button,"button task",1000,NULL,1,NULL);
  
}
void loop(){
  
}
TaskHandle_t ledTaskHandle = NULL;
void Task_sensor(void *paramerters){
  pinMode(4,INPUT_PULLUP);
  while(1){
    int sensor_value = random(0,100);
    xTaskNotify(ledTaskHandle,sensor_value,eSetValueWithoutOverwrite);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}

void task_led(void *pvParameters){
  pinMode(2,OUTPUT);
  uint32_t receivedValue;
  while(1){
    if(xTaskNotifyWait(0,0,&receivedValue,portMAX_DELAY) == pdTRUE){
      Serial.printf("[led task] got the sensor value: %d\n",receivedValue);
      if(receivedValue > 50){
        digitalWrite(2,HIGH);
      }else{
        digitalWrite(2,LOW);
      }
    }
  }
}
void setup(){
  Serial.begin(115200);
  delay(1000);
  xTaskCreate(task_led,"led task",1000,NULL,1,&ledTaskHandle);
  xTaskCreate(Task_sensor,"tasksensor",1000,NULL,1,NULL);
}
void loop(){
  
}

#define button_pin 4
#define led_pin 2
#define buzzer_pin 15
#define sensor_pin 16

TaskHandle_t ledTaskHandle = NULL;
TaskHandle_t buzzerTaskHandle = NULL;
TaskHandle_t sensorTaskHandle = NULL;

QueueHandle_t sensorQueue;

void IRAM_ATTR buttonISR(){   //isr has no printf data or malloc 
  BaseType_t xHighPriorityTaskWoken = pdFALSE;
  vTaskNotifyGiveFromISR(ledTaskHandle, &xHighPriorityTaskWoken);
  if(xHighPriorityTaskWoken) portYIELD_FROM_ISR();
}

hw_timer_t *timer = NULL;
void IRAM_ATTR timerISR(){
  BaseType_t xHigherPriorityTaskWoken = pdFALSE;
  vTaskNotifyGiveFromISR(buzzerTaskHandle, &xHigherPriorityTaskWoken);
  if(xHigherPriorityTaskWoken) portYIELD_FROM_ISR();
}

void IRAM_ATTR sensorISR() {
    int sensorValue = digitalRead(sensor_pin);
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;
    xQueueSendFromISR(sensorQueue, &sensorValue, &xHigherPriorityTaskWoken);
    if (xHigherPriorityTaskWoken) portYIELD_FROM_ISR();
}


void task_led(void *pvParameters){
  pinMode(led_pin,OUTPUT);
  while(1){
    ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
    digitalWrite(led_pin, !digitalRead(led_pin));
  }
}

void task_buzzer(void *pvParameters){
  pinMode(buzzer_pin,OUTPUT);  
  while(1){
    ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
    digitalWrite(buzzer_pin,HIGH);   
    vTaskDelay(100 / portTICK_PERIOD_MS);
    digitalWrite(buzzer_pin,LOW);
  }
}
void task_sensor(void *pvParameters){
  int sensorValue;
  while(1){
    if(xQueueReceive(sensorQueue, &sensorValue, portMAX_DELAY)){
      Serial.print("sensor data:");
      Serial.println(sensorValue);
    }
  }
}
void setup(){
  Serial.begin(115200);
    pinMode(button_pin,INPUT_PULLUP);
    pinMode(sensor_pin,INPUT);
    sensorQueue = xQueueCreate(10,sizeof(int));

    xTaskCreate(task_buzzer, "task buzzer", 2048, NULL, 1, &buzzerTaskHandle);
    xTaskCreate(task_led, "led task", 2048, NULL, 1, &ledTaskHandle);
    xTaskCreate(task_sensor, "sensor task", 2048, NULL, 1, &sensorTaskHandle);


    attachInterrupt(digitalPinToInterrupt(button_pin),buttonISR,FALLING);

    attachInterrupt(digitalPinToInterrupt(sensor_pin),sensorISR,RISING);

    timer = timerBegin(0,80,true);
    timerAttachInterrupt(timer,&timerISR,true);
    timerAlarmWrite(timer,1000000,true);
    timerAlarmEnable(timer);
  
}
void loop(){

}
TaskHandle_t ledTaskHandle = NULL;
void Task_for_button(void *pvParameters){
  pinMode(4,INPUT_PULLUP);
  int msg = 2;
  while(1){
      if(digitalRead(4) == LOW){
        Serial.println("data transfer in 2 deley time when button press");
        vTaskDelay(200 / portTICK_PERIOD_MS);
      }
      vTaskDelay(50 / portTICK_PERIOD_MS);  //  50 / 1000 delay(messages);
    
  }
}
  

void Task_arrow_show(void *pvParameters){
  pinMode(3,OUTPUT);
  for(;;){
    int count = ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
    if(count > 0){
      static int pass_count = 0;
      pass_count++;
      if(pass_count == 1){
        Serial.println("[led is ok push the button]");
      }
      else if(pass_count == 4){
        Serial.println("[push the 4 button get a message]");
      }
      else if(pass_count == 5){
        Serial.println("[led is bulking on real time......]");

      }
      // ulTaskGenericNotifyTake(pdTRUE,portMAX_DELAY);
      // ulTaskGenericNotifyTake(pdTRUE, portMAX_DELAY);
      // ulTaskGenericNotifyTake(pdTRUE, portMAX_DELAY);

      digitalWrite(3, !digitalRead(3));
      Serial.println("[led task led did not bulking off]");


      }
    }
}
// setup the void call data)
void setup(){
  Serial.begin(115200);
  delay(1000);
  xTaskCreate(Task_for_button,"task button to play",2024,NULL,1,&ledTaskHandle);
  xTaskCreate(Task_arrow_show,"task to arrow",2024,NULL,1,NULL);
}

void loop(){

}

void Task1(void *pvParameters){
  // pinMode(4,INPUT_PULLUP);
  while(1){
    Serial.println("task one data send ");
    vTaskDelay(50/portTICK_PERIOD_MS);
  }
}

void Task2(void *pvParameters){
  // pinMode(2,INPUT_PULLUP);
  while(1){
    Serial.println("task data 2 send");
    vTaskDelay(50 / portTICK_PERIOD_MS);

  }
}

void setup(){
  Serial.begin(115200);
  delay(1000);
  xTaskCreate(Task1,"task on send data",1000,NULL,1,NULL);
  xTaskCreate(Task2,"task 2 data send",1200,NULL,1,NULL);
}
void loop(){
  
}

// with mutex
#include <Arduino.h>
SemaphoreHandle_t xMutex;
void Task1(void *pvParameters){
    while(1){
        if(xSemaphoreTake(xMutex, portMAX_DELAY) == pdTRUE){
            Serial.println("Task 1  send the data");
            xSemaphoreGive(xMutex);

        }
        vTaskDelay(10 / portTICK_PERIOD_MS);  
    }
}

void Task2(void *pvParameters){
    while(1){
        if(xSemaphoreTake(xMutex,portMAX_DELAY) == pdTRUE){
           Serial.println("task 2 send the data");
           xSemaphoreGive(xMutex);
        }
        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
}
void setup(){
    Serial.begin(115200);
    delay(1000);
    xMutex = xSemaphoreCreateMutex();
    xTaskCreate(Task1,"task one send",1000,NULL,1,NULL);
    xTaskCreate(Task2,"task two data send",2000,NULL,1,NULL);
}
void loop(){

}

#include <Arduino.h>
#include <freertos/FreeRTOS.h>
#include <freertos/event_groups.h>

EventGroupHandle_t systemEventGroup;

#define SENSOR_READY (1 << 0)
#define WIFI_READY   (1 << 1)

void Task_sensor_ready(void *pvParameters) {
    Serial.println("Starting Sensor Task");
    vTaskDelay(2000 / portTICK_PERIOD_MS);
    Serial.println("Sensor initialized");
    xEventGroupSetBits(systemEventGroup, SENSOR_READY);
    vTaskDelete(NULL);
}

void Task_wifi(void *pvParameters) {
    Serial.println("Starting WiFi Task");
    vTaskDelay(3000 / portTICK_PERIOD_MS);
    Serial.println("WiFi initialized");
    xEventGroupSetBits(systemEventGroup, WIFI_READY);
    vTaskDelete(NULL);
}

void Task_motor(void *pvParameters) {
    Serial.println("Motor Task: Waiting for Sensor and WiFi...");
    EventBits_t bits = xEventGroupWaitBits(
        systemEventGroup,
        SENSOR_READY | WIFI_READY,
        pdFALSE,
        pdTRUE,
        portMAX_DELAY
    );
    Serial.println("System ready! Motor can start");
    vTaskDelay(5000 / portTICK_PERIOD_MS); // Keep task alive for 5 seconds
    vTaskDelete(NULL);
}

void setup() {
    Serial.begin(115200);
    delay(2000); // Wait for serial to stabilize
    Serial.println("Setup started");

    systemEventGroup = xEventGroupCreate();
    if (systemEventGroup == NULL) {
        Serial.println("Failed to create Event Group!");
        Serial.flush();
        while (1);
    }
    Serial.println("Event Group created");

    xTaskCreate(Task_sensor_ready, "Sensor", 4096, NULL, 1, NULL);
    xTaskCreate(Task_wifi, "WiFi", 4096, NULL, 1, NULL);
    xTaskCreate(Task_motor, "Motor", 8192, NULL, 1, NULL);
    Serial.println("Tasks created");
}

void loop() {
    vTaskDelay(100 / portTICK_PERIOD_MS);
}


QueueHandle_t dataQueue;

void TaskProducer(void *pvParameters){
    int value = 0;
    while(1){
        value++;
        if(xQueueSend(dataQueue, &value, portMAX_DELAY) == pdPASS){
            Serial.print("product");
            Serial.println(value);
        }
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
void Task_consumer(void *pvParameters){
    int receivedValue;
    while(1){
        if(xQueueReceive(dataQueue, &receivedValue, portMAX_DELAY) == pdPASS){
            Serial.print("consumed: ");
            Serial.println(receivedValue);
        }
    }
}
void setup(){
    Serial.begin(115200);
    delay(1000);
    dataQueue = xQueueCreate(5,sizeof(int));
    if(dataQueue == NULL){
        Serial.println("queue creation faild");
        while(1);

        }
    xTaskCreate(TaskProducer, "producer", 2024,NULL,1,NULL);
    xTaskCreate(Task_consumer,"councmer",2024,NULL,1,NULL);
    
}
void loop(){

}

#define BUTTON_PIN 4
#define LED_PIN    2
TaskHandle_t ledTaskHandle = NULL;

void IRAM_ATTR button(){   // ISR for the button
   BaseType_t xhigforse = pdFALSE;
   vTaskNotifyGiveFromISR(ledTaskHandle, &xhigforse);
   if(xhigforse){
    portYIELD_FROM_ISR();
   }
}

void Task_Led(void *pvParameters){
    pinMode(LED_PIN,OUTPUT);
    bool ledState = false;
    while(1){
        ulTaskNotifyTake(pdTRUE,portMAX_DELAY);
        ledState = !ledState;
        digitalWrite(LED_PIN, ledState);
        Serial.println(ledState ? "led on" : "led off");
    }
}
void setup(){
    Serial.begin(115200);
    delay(1000);
    pinMode(BUTTON_PIN,INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(BUTTON_PIN),button,FALLING);
    xTaskCreate(Task_Led,"led Task",2048,NULL,1,&ledTaskHandle);
}

void loop(){

} 

#define LED_POP_PIN 2
TimerHandle_t blinkTimer;

void Blink_call_back(TimerHandle_t xTimer);
static bool ledState = false;

void Blink_call_back(TimerHandle_t xTimer) {
	ledState = !ledState;
	digitalWrite(LED_POP_PIN, ledState);
    Serial.println(ledState ? "led on" : "led off");
}

void setup(){
    Serial.begin(115200);
    delay(1000);
    pinMode(LED_POP_PIN, OUTPUT);

    blinkTimer = xTimerCreate(
        "BlinkTimer",
        pdMS_TO_TICKS(500),  // 500ms
        pdTRUE,              // auto-reload(repeats)
        (void*)0,
        Blink_call_back


    );
    if(blinkTimer != NULL){
        xTimerStart(blinkTimer, 0);   // start timer  ....
    }else{
        Serial.println("failed to create timer!");
    }
}

void loop(){

}
