#include<stdio.h>
#include<stdlib.h>
void stack_example(){
    int stack_array[5] = {1,2,3,4,5};
    printf("stack array address: %p\n",(void*)stack_array);
    return;
}
void heap_example(){
    int* heap_array = (int*)malloc(10000 *sizeof(int));
    if (heap_array == NULL){
        printf("MEMORY ALLOCATION FAILED\n");
        return;
    }
    for(int i=0;i<10000;i++){
        heap_array[i] = i+1;
    printf("heap array address: %p\n",(void*)heap_array);
    free(heap_array);
    // heap_array = NULL;
    free(heap_array);
}
}
int main(){
    stack_example();
    heap_example();
    return 0;
}
    