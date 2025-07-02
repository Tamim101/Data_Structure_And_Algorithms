// #include<stdio.h>
// int main(){
// int heap_size = 9;
// int heap[] = {0,19,7,17,3,5,12,10,1,2};

// heap[1] =19;
// heap[2] = 7;
// heap[3] = 17;
// heap[2*2] = 3;
// heap[2*2 + 1] = 5;
// heap[3*2] = 12;
// heap[3*2 +1 ] = 10;
// heap[4*2] = 1;
// heap[4*2 +1] = 2;
// for (int i = 1; i <= heap_size; i++) {
//         printf("heap[%d] = %d\n", i, heap[i]);
//     }

//     return 0;
// }
#include <stdio.h>

// Left child of node i
int left(int i) {
    return 2 * i;
}
// Right child of node i
int right(int i) {
    return 2 * i + 1;
}

// Maintain max-heap property
void max_heapify(int heap[], int heap_size, int i) {
    int l = left(i);
    int r = right(i);
    int largest = i;

    if (l <= heap_size && heap[l] > heap[largest]) {
        largest = l;
    }

    if (r <= heap_size && heap[r] > heap[largest]) {
        largest = r;
    }

    if (largest != i) {
        int temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;

        // Safe recursive call
        max_heapify(heap, heap_size, largest);
    }
}

// Convert array into a max-heap
void build_max_heap(int heap[], int heap_size) {
    for (int i = heap_size / 2; i >= 1; i--) {
        max_heapify(heap, heap_size, i);
    }
}

// Main function
int main() {
    int heap_size = 9;
    int heap[] = {0, 19, 7, 17, 3, 5, 12, 10, 1, 2};  // index starts at 1

    build_max_heap(heap, heap_size);

    for (int i = 1; i <= heap_size; i++) {
        printf("HEAP[%d] = %d\n", i, heap[i]);
    }

    return 0;
}

#include <stdio.h>
int left(int i){
    return 2* i;
}
int right(int i){
    return 2* i +1;
}
void heap_line(int heap[],int heap_size,int i){
     int l,r;
     l = left(i);
     r = right(i);
     int largest = i;
     if(i<=heap_size && heap[l] > heap[largest]){
        return l;
     }
     if(i<=heap_size && heap[r]>heap[largest]){
        return r;
     }
     if(largest != i){
        int t = heap[i];
        heap[i] = heap[largest];
        heap[largest] = t;
        
     }
     heap_line(heap,heap_size,i);
}