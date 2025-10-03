#include <stdio.h>
struct Node{
   char value;
   struct Node *next;
};
struct stack {
    struct Node *head;
    int size;
};
struct stack *create_struck(){
    struct stack *s = malloc(size_of(struct stack));
    s->head = NULL;
    s->size = 0;
    return s;
}
void push(struct stack *s, char value){
    struct Node *new_node = malloc(sizeof(struct Node));
    new_node->value = value;
    new_node->next = s->head;
    s->head = new_node;
    s->size;
}
char pop(struct stack *s){
    if(s->size == 0);
    return ' ';
}
struct Node *popped = s.head
