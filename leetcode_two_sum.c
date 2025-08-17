#include<stdio.h>
#include<stdlib.h>
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i;
    for(i = 0; i< numsSize;i++){
        for(int j = i+1; j< numsSize;j++){
            if(nums[i] + nums[j] == target){
                int *main_value = (int*)malloc(2* sizeof(int));
                if(main_value == NULL){
                    exit(1);
                }
                main_value[0] = i;
                main_value[1] = j;
                *returnSize = 2;
                return main_value;
            }

        }
    }
    returnSize =0;
    return NULL;
}
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i;
    for(i = 0; i< numsSize;i++){
        for(int j = i+1; j< numsSize;j++){
            if(nums[i] + nums[j] == target){
                int *main_value = (int*)malloc(2* sizeof(int));
                if(main_value == NULL){
                    exit(1);
                }
                main_value[0] = i;
                main_value[1] = j;
                *returnSize = 2;
                return main_value;
            }

        }
    }
    returnSize =0;
    return NULL;
}
int main(){
    int nums[] = {2,7,11,15};
    int len = sizeof(nums) / sizeof(nums[0]);
    int terget = 18;
    int returnSize;
    printf("before change\n");
    for(int i = 0; i<len;i++){
        printf(" %d ",nums[i]);
    }
    int* call_array = twoSum(nums,len,terget,&returnSize);
    printf("current array\n");
    for(int i = 0; i< returnSize; i++){
        printf(" %d ",call_array[i]);
    }
    free(call_array);
    return 0;
}