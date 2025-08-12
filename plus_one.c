#include<stdio.h>
#include<stdlib.h>
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int *digits = (int *)malloc(sizeof(digits));
    int i;
    for(i = 0; i < digitsSize; i++){
        if(digits[i] != ','){
            digits[i] = digits[i]+1;
            return digits;
        }
    }
}

