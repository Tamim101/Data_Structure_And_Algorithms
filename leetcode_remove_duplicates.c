#include<stdio.h>
int remove_duplicates(int* nums, int numsSize){
    if(numsSize == 0){
        return 0;  // if number is blank so number size or len number is 0
    }
    int i = 0 ; // first index is 0 len number is 0 that means input 112233
    for(int j= 1; j<numsSize; j++){
                                 //j =1 thats mean index 1 
        if(nums[j] != nums[i]){
                            // number 1 == 1 is same but 1 != 2  
          i++ ;   // so its take 2
          nums[i] = nums[j] ;
          printf("num i = %d\n num j %d\n",nums[i],nums[j]);
        }
    }
    return i+1 ; // i incriment 

}
int main(){
    int nums[] = {1,1,2,2,3,4,4,5};
    int size = sizeof(nums) / sizeof(nums[0]);
    int remove_length = remove_duplicates(nums,size);  // just call remove_duplicates value
    printf("AFTER REMOVING DUPLICATES : ");
    for(int i = 0; i < remove_length; i++){
        printf("%d",nums[i]);
    }
    printf("\nNEW LENGTH = %d\n",remove_length);
    return 0;
}