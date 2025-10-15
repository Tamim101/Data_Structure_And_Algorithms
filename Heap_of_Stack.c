#include<stdio.h>
#include<stdlib.h>
void stack_example(){
    int stack_array[5] = {1,2,3,4,5};
    printf("stack array address: %u\n",(void*)stack_array);
    return;
}
void heap_example(){
    int* heap_array = (int*)malloc(100000 *sizeof(int));
    if (heap_array == NULL){
        printf("MEMORY ALLOCATION FAILED\n");
        return;
    }
    for(int i=0;i<100000;i++){
        heap_array[i] = i+1;
    printf("heap array address: %u\n",(void*)heap_array);
    free(heap_array);
    heap_array = NULL;
    free(heap_array);
}
}
void heap_extra_data(){
    int* heap_count = (int*)malloc(10000 * sizeof(int));
    if(heap_count == NULL){
        printf("memory allocation faild");
        return 0;
    }
    for(int j = 0; j < 10000; j++){
        heap_count[j] = j+1;
    printf("heap count address: %u\n",(void*)heap_count);
    free(heap_count);
    heap_count = NULL;
    free(heap_count);
    }
}

int main(){
    stack_example();
    heap_example();
    heap_extra_data();
    return 0;
}
    