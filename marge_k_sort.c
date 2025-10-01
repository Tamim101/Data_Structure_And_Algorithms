#include<stdlib.h>
#include<stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
 };

int constant_value(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
 }

// Helper function to create a new ListNode
struct ListNode* createNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Helper function to print a linked list
void printList(struct ListNode* head) {
    struct ListNode* curr = head;
    while (curr != NULL) {
        printf("%d ", curr->val);
        curr = curr->next;
    }
    printf("\n");
}


 struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if(listsSize == 0){
        return NULL;
    }
    int total = 0;
    for(int i = 0; i < listsSize; i++){
        struct ListNode *curr = lists[i];
        while(curr != NULL){
            total++;
            curr = curr->next;
        }
    }
    if(total == 0){
        return NULL;
    }
    int *temp = (int*)malloc(sizeof(int) * total);
    if(temp == NULL){
       return NULL;
    }
    int index = 0;
    for(int i = 0; i < listsSize; i++){
        struct ListNode *curr = lists[i];
        while(curr != NULL){
            temp[index++] = curr->val;
            curr = curr->next;
        }
    }
    qsort(temp, total, sizeof(int), constant_value);
    
    struct ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode));
    if(head == NULL){
        free(temp);
        return NULL;
    }
    head->val = temp[0];
    head->next = NULL;
    struct ListNode *curr = head;
    for(int i = 1; i < total;i++){
        curr->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        if(curr->next == NULL){

        }
        curr = curr->next;
        curr->val = temp[i];
        curr->next = NULL;
    }
    free(temp);
    return head;

 }

int main() {
    // Create test case: three sorted linked lists
    // List 1: 1 -> 4 -> 5
    struct ListNode* list1 = createNode(1);
    list1->next = createNode(4);
    list1->next->next = createNode(5);
    
    // List 2: 1 -> 3 -> 4
    struct ListNode* list2 = createNode(1);
    list2->next = createNode(3);
    list2->next->next = createNode(4);
    
    // List 3: 2 -> 6
    struct ListNode* list3 = createNode(2);
    list3->next = createNode(6);
    
    // Array of lists
    struct ListNode* lists[] = {list1, list2, list3};
    int listsSize = 3;
    
    // Print input lists
    printf("Input lists:\n");
    for (int i = 0; i < listsSize; i++) {
        printf("List %d: ", i + 1);
        printList(lists[i]);
    }
    
    // Merge lists
    struct ListNode* merged = mergeKLists(lists, listsSize);
    
    // Print merged list
    printf("Merged list: ");
    printList(merged);
    
    // Free memory (omitted for brevity, but you should free all allocated nodes)
    
    return 0;
}
#include <Arduino.h>
#include <freertos/FreeRTOS.h>
#include <freertos/event_groups.h>
#include <WiFi.h>

EventGroupHandle_t wifiGroup;
#define WIFI_CONNECTION (1 << 0)

const char* ssid = "Tamim-wifi";
const char* pass = "tamim9047@";

void Task_Network(void *pv){
    xEventGroupWaitBits(wifiGroup, WIFI_CONNECTION,pdFALSE,pdTRUE,portMAX_DELAY);
    Serial.println("now start mqtt or sensor task");
    vTaskDelete(NULL);

}
void setup(){
    Serial.begin(115200);
    wifiGroup = xEventGroupCreate();
    WiFi.begin(ssid,pass);
    while(WiFi.status() != WL_CONNECTED){
        delay(500);
    }
    xEventGroupSetBits(wifiGroup,WIFI_CONNECTION);
    xTaskCreate(Task_Network,"net task",4096,NULL,1,NULL);
}
void loop(){
    
}

#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 16, 2); // Use I2C scanner to confirm address

void setup() {
  Wire.begin(10, 9); // ESP32-C3 I2C pins
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("ESP32-C3 LCD");
  lcd.setCursor(0,1);
  lcd.print("FreeRTOS Demo");
}

void loop() {}
