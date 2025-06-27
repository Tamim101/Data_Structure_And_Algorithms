#include <stdio.h>
#include <stdlib.h>

int main() {
    int nums[] = {2, 7, 4, 15};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 19;
    int returnSize = 0;                   
    int* result = NULL;                     
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                result = (int*)malloc(2 * sizeof(int));
                if (result == NULL) {
                    printf("Memory allocation failed\n");
                    exit(1);
                }
                result[0] = i;
                result[1] = j;
                returnSize = 2;              
                                   
            }
        }
    }
    if (returnSize == 2 && result != NULL) {
        printf("Indices: [%d, %d]\n", result[0], result[1]);
        free(result);                      
    } else {
        printf("No two numbers add up to the target.\n");
    }

    return 0;
}
//leadcode problem twosum [1,4,5,6] [0,1]
#include<stdio.h>
#include<stdlib.h>
int* twosum(int* nums,int numsSize,int target,int* returnSize){
          for(int i = 0; i < numsSize; i++){
            for(int j = i + 1; j < numsSize; j++){
                if(nums[i] + nums[j] == target){
                    int* result = (int*)malloc(2 * sizeof(int));
                    if(result == NULL){
                        exit(1);
                    }
                    result[0] = i;
                    result[1] = j;
                    returnSize = 2;
                    if(returnSize == 2 && result != NULL){
                        free(result);

                    }else{
                        free(result);
                    }
                    return 0;
                }
            }
          }
          
}