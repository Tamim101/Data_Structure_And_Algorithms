#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;   
}node;
typedef struct node Node;
struct Node{
    int data;
    Node *next;
};
Node *create_node(int item,Node *next){
    Node *new_node = (Node *) malloc(sizeof(Node));
    if(new_node == NULL){
        printf("Error could not create a new node");
        exit(1);
    }
    new_node->data = item;
    new_node->next = next;
    return new_node;
}

Node *remove_node(Node *head,Node *node){
    if(node == head){
        head = node->next;
        free(node);
        return head;
    }
    Node *current_node = head;
    while(current_node != NULL){
        if(current_node->next == node){
            break;
        }
        current_node = current_node->next;
    }
    if(current_node == NULL){
        return head;
    }
    current_node->next = node->next;
    free(node);
    return head;
}

void print_list(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d = ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}


int main() {
    Node *n, *n1, *n2, *n3, *head;

    // Create nodes
    n = create_node(10, NULL);
    n1 = create_node(24, NULL);
    n2 = create_node(44, NULL);
    n3 = create_node(55, NULL);

    // Link the nodes to form the list: 10 -> 24 -> 44 -> 55
    n->next = n1;
    n1->next = n2;
    n2->next = n3;

    // Set the head of the list
    head = n;

    // Print initial data
    printf("Initial list:\n");
    print_list(head);

    // Remove node with value 55 (n3)
    head = remove_node(head, n2);

    printf("After removing 55:\n");
    print_list(head);

    // Cleanup: free remaining memory
    head = remove_node(head, n1);
    head = remove_node(head, n3); // n2 is now not in the list (already removed above)
    head = remove_node(head, n);  // finally remove the head node

    return 0;
}
