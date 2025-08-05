#include<stdio.h>
int removeElement(int* nums, int numSize, int val){
    int i,j;
    for(i = 0; i < numSize; i++){
        if(nums[i] != val){
            nums[j] = nums[i];
            j++;
        }
    }
    return j;
}

int main(){
    int nums[] = {3,2,2,3,4}; // 3 and 3 remvoed
    int val = 3;
    int len = sizeof(nums) / sizeof(nums[0]);
    int new_len_number = removeElement(nums,len,val);
    printf("NEW LEN NUMBER %d\n",new_len_number);
    printf("Nodified array = ");
    for(int i = 0 ; i < new_len_number;i++){
        printf("%d\n",nums[i]);
    }
    return 0;
}