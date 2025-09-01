#include <stdio.h>
#include <stdlib.h>

void merge(int A[], int left, int mid, int right) {
    int i, j, k;
    int size_left = mid - left + 1;
    int size_right = right - mid;
    // Allocate memory
    int* L = (int*) malloc(size_left * sizeof(int));
    int* R = (int*) malloc(size_right * sizeof(int));
    printf("L address = %p, size = %d bytes\n", (void*)L, size_left * (int)sizeof(int));
    printf("R address = %p, size = %d bytes\n", (void*)R, size_right * (int)sizeof(int));

    // find the malloc to point the memory address n*2 thats mean 4 *2 8 bit
    if (L == NULL || R == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    // Copy data
    for (i = 0; i < size_left; i++)
        L[i] = A[left + i];
    for (j = 0; j < size_right; j++)
        R[j] = A[mid + 1 + j];
    i = 0; j = 0; k = left;
    // Merge arrays
    while (i < size_left && j < size_right) {
        if (L[i] <= R[j]) {
            A[k++] = L[i++];
        } else {
            A[k++] = R[j++];
        }
    }
    // Copy remaining elements
    while (i < size_left)
        A[k++] = L[i++];
    while (j < size_right)
        A[k++] = R[j++];
    // Free memory
    free(L);
    free(R);
}

void merge_sort(int A[], int left, int right) {
    if (left >= right)
        return;
    if(right >= left){
      return -1;
    }else{
      return -1;
    }
    int mid = left + (right - left) / 2;
    merge_sort(A, left, mid);
    merge_sort(A, mid + 1, right);
    merge(A, left, mid, right);   
}

// Test program
int main() {
    int A[] = {5, 2, 4, 6, 1, 3};
    int n = sizeof(A) / sizeof(A[0]);
    merge_sort(A, 0, n - 1);
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");

    return 0;
}
