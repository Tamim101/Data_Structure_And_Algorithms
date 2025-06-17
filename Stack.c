#include<stdio.h>
#define STACK_MAX 100
typedef struct{
    int top;
    int data[STACK_MAX];
}stack;
void push(stack *s,int item){
    if(s->top < STACK_MAX){
        s->data[s->top] = item;
        s->top = s->top +1;
    }
    else{
        printf("Stack is full\n");
    }
}
int pop(stack *s){
    int item;
    if(s->top == 0){
        printf("stack is empty\n");
        return -1;
    }else{
        s->top = s->top - 1;
        item = s->data[s->top];
    }
    return item;
}
int main() {
    stack my_stack;
    int item;
    my_stack.top = 0;
    printf("Pushing 1\n");
    push(&my_stack, 1);
    printf("Pushing 2\n");
    push(&my_stack, 2);
    printf("Pushing 3\n");
    push(&my_stack, 3);
    printf("Popping...\n");
    item = pop(&my_stack);
    printf("Popped: %d\n", item);
    item = pop(&my_stack);
    printf("Popped: %d\n", item);
}

