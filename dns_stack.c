#include <stdio.h>
#include <stdlib.h>
struct Node{
   char value;
   struct Node *next;
};
struct stack {
    struct Node *head;
    int size;
};
struct stack *create_struck(){
    struct stack *s = malloc(sizeof(struct stack));
    s->head = NULL;
    s->size = 0;
    return s;
}
void push(struct stack *s, char value){
    struct Node *new_node = malloc(sizeof(struct Node));
    new_node->value = value;
    new_node->next = s->head;
    s->head = new_node;
    s->size++;
}
char pop(struct stack *s){
    if(s->size == 0){
        return ' ';
    }
    struct Node *popped = s->head;
    s->head = s->head->next;
    char popped_value = popped->value;
    free(popped);
    s->size--;
    return popped_value;  
}
char peek(struct stack *s){
    if(s->size == 0){
        return ' ';
    }
    return s->head->value;
}
int is_empty(struct stack *s){
    return s->size == 0;
}  
int stack_size(struct stack *s){
    return s->size;
}
int main(){
    struct stack *my_stack = create_struck();
    push(my_stack,'a');
    push(my_stack,'b');
    push(my_stack,'c');

    printf("pop: %c\n", pop(my_stack));
    printf("peek: %c\n", peek(my_stack));
    printf("is_empty: %d\n", is_empty(my_stack));
    printf("size: %d\n", stack_size(my_stack));
}




