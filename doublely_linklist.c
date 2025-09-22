// #include<stdio.h>
// #include<stdlib.h>
// typedef struct Node{
//     int data;
//     struct Node* next;
//     struct Node* prev;
// }Node;
// int main(){
//     Node* node1 = (Node*)malloc(sizeof(Node));
//     node1->data = 3;
//     node1->next = NULL;
//     node1->prev = NULL;

//     Node* node2 = (Node*)malloc(sizeof(Node));
//     node2->data = 5;
//     node2->next = NULL;
//     node2->prev = node1;
//     node1->next = node2;
    
//     Node* node3 = (Node*)malloc(sizeof(Node));
//     node3->data = 13;
//     node3->next = NULL;
//     node3->prev = node2;
//     node2->next = node3;

//     Node* currentNode = node1;
//     printf("forward: ");
//     while(currentNode){
//         printf("%d ->",currentNode->data);
//         currentNode = currentNode->next;
//     }
//     printf("NULL\n");
//     currentNode = node3;
//     printf("Backward: ");
//     while(currentNode){
//         printf("%d->",currentNode->data);
//         currentNode = currentNode->prev;
//     }
//     printf("NULL\n");
//     free(node1);
//     free(node2);
//     free(node3);
//     return 0;
// }


// #include<stdio.h>
// #include<stdlib.h>
// typedef struct Node{
//     int data;
//     struct Node* next;

// }Node;
// void traversen_and_print(Node* head){
//     Node* current_node = head;
//     while(current_node != NULL){
//         printf("%d ->",current_node->data);
//         current_node = current_node->next;
//     }
//     printf("NULL\n");
// }

// leetcode problem 
#include<stdio.h>
#include<stdlib.h>
struct ListNode {
    int val;
    struct ListNode* next;
};
void traversen_and_print(struct ListNode* head){
    struct ListNode* current_node = head;
    while(current_node != NULL){
        printf("%d ->",current_node->val);
        current_node = current_node->next;
    }
    printf("NULL\n");
}
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
       int length = 0;
       struct ListNode* temp = head;
       while(temp != NULL){
        length++;
        temp = temp->next;

       }
       if(n == length){
        struct ListNode*  new_node = head->next;
        free(head);
        return new_node;
       }
       temp = head;
       for(int i = 1; i < length-n; i++){
        temp = temp->next;

       }
       struct ListNode* del = temp->next;
       temp->next = temp->next->next;
       free(del);
       return head;
}


int main() {
    struct ListNode* head = malloc(sizeof(struct ListNode));   // Create linked list
    head->val = 1;
    head->next = malloc(sizeof(struct ListNode));
    head->next->val = 2;
    head->next->next = malloc(sizeof(struct ListNode));
    head->next->next->val = 3;
    head->next->next->next = malloc(sizeof(struct ListNode));
    head->next->next->next->val = 4;
    head->next->next->next->next = malloc(sizeof(struct ListNode));
    head->next->next->next->next->val = 5;
    head->next->next->next->next->next = NULL;

    printf("Original List: ");
    traversen_and_print(head);

    int n = 3; 
    head = removeNthFromEnd(head, n);

    printf("After removing %dth node from end: ", n);
    traversen_and_print(head);


    while (head != NULL) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
// // delete node 

// Node* delete_specific_node(Node* head, Node* nodetodelete){
//     if(head == nodetodelete){
//         Node* newhead = head->next;
//         free(head);
//         return newhead;
//     }
//     Node* current_node = head->next;
//     while(current_node->next && current_node->next != nodetodelete){
//         current_node = current_node->next;
//     }
//     if(current_node->next == NULL){
//         return head;
//     }
//     Node* temp = current_node->next;
//     current_node->next = current_node->next->next;
//     free(temp);
//     return head;

// }
// Node* delete_spacifi_node2(Node* head, Node* node2todelete){
//     if(head == node2todelete){
//         Node* new_node = head->next;
//         free(head);
//         return new_node;
//     }
//     Node* current_node = head->next;
//     while(current_node->next && current_node->next != node2todelete){
//         current_node = current_node->next;
//     }
//     if(current_node->next = NULL){
//         return head;
//     }
//     Node* temp = current_node->next;
//     current_node->next = current_node->next->next;
//     free(temp);
//     return head;
// }

// int main(){
//     Node* node1 = (Node*)malloc(sizeof(Node));
//     node1->data = 7;
//     Node* node2 = (Node*)malloc(sizeof(Node));
//     node2->data = 12;
//     Node* node3 = (Node*)malloc(sizeof(Node));
//     node3->data = 13;
//     Node* node4 = (Node*)malloc(sizeof(Node));
//     node4->data = 12;
//     Node* node5 = (Node*)malloc(sizeof(Node));
//     node5->data = 9;
//     node1->next = node2;
//     node2->next = node3;
//     node3->next = node4;
//     node4->next = node5;
//     node5->next = NULL;
//     printf("before data :\n ");
//     traversen_and_print(node1);

//     delete_specific_node(node1,node4);
//     printf("After data :\n ");
//     traversen_and_print(node1);
//     free(node1);
//     free(node2);
//     free(node3);
//     free(node5);
//     return 0;
// }

// struct Node{
//     int data ;
//     struct Node* next;

// };
// int find_lowest_value(struct Node* head){
//     int main_value = head->data;
//     struct Node* currentNode = head->next;
//     while(currentNode){
//         if(currentNode->data < main_value){
//             main_value = currentNode->data;
//         }
//         currentNode = currentNode->next;
        
//     }
//     return main_value;
// }
// int main(){
//     struct Node* node1 = (struct Node*)malloc(sizeof(struct Node));
//     struct Node* node2 = (struct Node*)malloc(sizeof(struct Node));
//     struct Node* node3 = (struct Node*)malloc(sizeof(struct Node));
//     struct Node* node4 = (struct Node*)malloc(sizeof(struct Node));
    
//     node1->data = 7;
//     node2->data =11;
//     node3->data =3;
//     node4->data = 2;
    
//     node1->next = node2;
//     node2->next = node3;
//     node3->next = node4;
//     node4->next = NULL;
//     printf("the lowest value is = %d\n",find_lowest_value(node1));
//     return 0;

// }


// leetcode problem solved with 
