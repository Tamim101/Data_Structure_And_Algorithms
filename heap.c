#include<stdio.h>
int main(){
int heap_size = 9;
int heap[] = {0,19,7,17,3,5,12,10,1,2};

heap[1] =19;
heap[2] = 7;
heap[3] = 17;
heap[2*2] = 3;
heap[2*2 + 1] = 5;
heap[3*2] = 12;
heap[3*2 +1 ] = 10;
heap[4*2] = 1;
heap[4*2 +1] = 2;
for (int i = 1; i <= heap_size; i++) {
        printf("heap[%d] = %d\n", i, heap[i]);
    }

    return 0;
}