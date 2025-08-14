#include<stdio.h>
int search_algrotham(int nums[], int len_array, int find_index){
    int i;
    for(i=0;i<len_array;i++){
        if(nums[i] == find_index){
            printf("return i %d\n",i);
            return i;
        }

    }
    return -1;
}
int main(){
    int nums[] = {12,3,5,6,77,8};
    int array_length = sizeof(nums) / sizeof(nums[0]);
    printf("array len = %d",array_length);
    int key = 9;
    int call_back_funcation = search_algrotham(nums,array_length,key);
    if(call_back_funcation == -1){
        printf("this is not found");
    }else{
        printf("this is the index = %d",call_back_funcation+1);
    }
    return 0;

}

#include<stdio.h>
#include <stdint.h> // uint8_t 
int insert_data(uint8_t nums[],uint8_t length, uint8_t key,uint8_t capacity){
    if(length >= capacity){
        printf("length = %d\n",length);
        return length;
    }
    nums[length] = key;
    printf("last = %d\n ",length+1);
    return length+1;

}
int main(){
    uint8_t nums[] = {1,3,4,5,6,7,3};
    uint8_t capacity = sizeof(nums) / sizeof(nums[0]);
    uint8_t length = 6;
    uint8_t key = 54;
    for(uint8_t i = 0; i<capacity;i++){
        printf("insert array = %d\n",nums[i]);
    }
    uint8_t call_array = insert_data(nums,length,key,capacity);
    for(uint8_t i = 0; i< call_array; i++){
        printf("insert at the end %d\n ",nums[i]);
    }
    printf("\n");
    return 0;

}