#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
}Node;
int main(){
    Node* node1 = (Node*)malloc(sizeof(Node));
    node1->data = 3;
    node1->next = NULL;
    node1->prev = NULL;

    Node* node2 = (Node*)malloc(sizeof(Node));
    node2->data = 5;
    node2->next = NULL;
    node2->prev = node1;
    node1->next = node2;
    
    Node* node3 = (Node*)malloc(sizeof(Node));
    node3->data = 13;
    node3->next = NULL;
    node3->prev = node2;
    node2->next = node3;

    Node* currentNode = node1;
    printf("forward: ");
    while(currentNode){
        printf("%d ->",currentNode->data);
        currentNode = currentNode->next;
    }
    printf("NULL\n");
    currentNode = node3;
    printf("Backward: ");
    while(currentNode){
        printf("%d->",currentNode->data);
        currentNode = currentNode->prev;
    }
    printf("NULL\n");
    free(node1);
    free(node2);
    free(node3);
    return 0;
}