// #include<stdio.h>
// int search_algrotham(int nums[], int len_array, int find_index){
//     int i;
//     for(i=0;i<len_array;i++){
//         if(nums[i] == find_index){
//             printf("return i %d\n",i);
//             return i;
//         }

//     }
//     return -1;
// }
// int main(){
//     int nums[] = {12,3,5,6,77,8};
//     int array_length = sizeof(nums) / sizeof(nums[0]);
//     printf("array len = %d",array_length);
//     int key = 9;
//     int call_back_funcation = search_algrotham(nums,array_length,key);
//     if(call_back_funcation == -1){
//         printf("this is not found");
//     }else{
//         printf("this is the index = %d",call_back_funcation+1);
//     }
//     return 0;

// }

// #include<stdio.h>
// #include <stdint.h> // uint8_t 
// int insert_data(uint8_t nums[],uint8_t length, uint8_t key,uint8_t capacity){
//     if(length >= capacity){
//         printf("length = %d\n",length);
//         return length;
//     }
//     nums[length] = key;
//     printf("last = %d\n ",length+1);
//     return length+1;

// }
// int main(){
//     uint8_t nums[] = {1,3,4,5,6,7,3};
//     uint8_t capacity = sizeof(nums) / sizeof(nums[0]);
//     uint8_t length = 6;
//     uint8_t key = 54;
//     for(uint8_t i = 0; i<capacity;i++){
//         printf("insert array = %d\n",nums[i]);
//     }
//     uint8_t call_array = insert_data(nums,length,key,capacity);
//     for(uint8_t i = 0; i< call_array; i++){
//         printf("insert at the end %d\n ",nums[i]);
//     }
//     printf("\n");
//     return 0;

// }

// #include <stdio.h>
// #include <stdint.h>

// void insert_data(uint8_t nums[], uint8_t length, uint8_t key, uint8_t poshion) {
    
//     for (uint8_t i = length - 1; i >= poshion; i--) {
//         nums[i + 1] = nums[i];
//     }
//     nums[poshion] = key;
// }

// int main() {
//     uint8_t array[6] = {2, 4, 1, 8, 5}; 
//     uint8_t length = 5;

//     printf("Before insert:\n");
//     for (uint8_t i = 0; i < length; i++) {
//         printf("%d ", array[i]);
//     }
//     printf("\n");

//     uint8_t key = 12;
//     uint8_t poshion = 4;

//     insert_data(array, length, key, poshion);
//     length++; 

//     printf("After insert:\n");
//     for (uint8_t i = 0; i < length; i++) {
//         printf("%d ", array[i]);
//     }
//     printf("\n");

//     return 0;
// }

// #include<stdio.h>
// int find_value(int arr[],int n,int key);
// int delete_element(int arr[],int n,int key){
//     int find_element = find_value(arr,n,key);
//     if(find_element == -1){
//         printf("ELEMENT NOT FOUND!");
//         return -1;
//     }
//     for(int i = find_element; i < n-1;i++){
//         arr[i] = arr[i+1];

//     }
//     return n-1;
// }

// int find_value(int arr[],int n,int key){
//     for(int i = 0; i < n; i++){
//         if(arr[i] == key);
//         return 1;
//     }
//     return -1;
// }
// int main(){
//     int arr[] = {1,3,4,5,6};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     int key = 3;
//     printf("BEFORE DELETE\n");
//     for(int i = 0; i< n; i++){
//         printf(" %d ",arr[i]);
//     }
//     int call_array = delete_element(arr,n,key);
//     printf("DELETE ELEMENT\n");
//     for(int i = 0; i< call_array;i++){
//         printf(" %d ",arr[i]);
//     }
//     return 0;
// }


// solved plus 1 
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include<stdio.h>
#include<stdlib.h>
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int i;
    int carry = 1;
    for(i = digitsSize -1; i>= 0;i-- ){
        digits[i] += carry;
        if(digits[i]>=10){
            digits[i] = 0;
            carry = 1;
        }else{
            carry = 0;
            break;
        }
    }
    if(carry == 1){
        int *new_array = (int*)malloc(sizeof(int)*(digitsSize +1));
        new_array[0] = 1;
        for(int i = 0; i<digitsSize;i++){
            new_array[i + 1] = digits[i];
        }
        *returnSize = digitsSize + 1;
        return new_array;
    }
    *returnSize = digitsSize;
    return digits;  
         
    }
int main(){
    int digits[] = {1,4,6,7};
    int len = sizeof(digits) / sizeof(digits[0]);
    int array = plusOne(digits,len);
    for(int i = 0; i< len;i++ ){
        // printf("%d ",digits[i]);

    }
    return 0;
}
