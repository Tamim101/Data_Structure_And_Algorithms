#include<stdio.h>
#include<stdlib.h>
typedef struct node Node;
struct node{
    int data;
    Node *next;
    Node *prev;
};
Node *create_node(int item,Node *next,Node *prev){
    Node *new_node = (Node *) malloc(sizeof(Node));
    if(new_node == NULL){
        printf("ERROR COULD NOT CREATE A NEW NODE\n");
        exit(1);
    }
    new_node->data = item;
    new_node->next = next;
    new_node->prev = prev;
    return new_node;
}
void print_list(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
int main() {
    Node *a, *b, *c, *d, *head;

    // Create nodes with NULL next and prev
    a = create_node(10, NULL, NULL);
    b = create_node(23, NULL, a);
    c = create_node(11, NULL, b);
    d = create_node(22, NULL, c);

    // Link the next pointers
    a->next = b;
    b->next = c;
    c->next = d;

    // Set head of the list
    head = a;

    printf("Doubly linked list:\n");
    print_list(head);

    return 0;
}