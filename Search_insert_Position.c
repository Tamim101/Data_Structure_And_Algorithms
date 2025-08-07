#include<stdio.h>
int serchInsert(int* nums,int numsSize, int target){
    int i;
    for(i = 0; i < numsSize; i++){
        if(nums[i] >= target){
            printf("target  = %d",i);
            return i;
        }
    }
    return numsSize;
        
    
}
int main(){
    int nums[] = {1, 3, 5, 6};
    int target = 7;
    int len  = sizeof(nums) / sizeof(nums[0]);
    int new_len_number  = serchInsert(nums,len,target);
    printf("nuw len number = %d\n",new_len_number);
    printf("array = ");
    for(int i = 0 ; i< new_len_number;i++){
        printf("%d\n",nums[i]);
    }
    printf("\n");
    return 0;

}
int main(){
    int nums[] = {1, 3, 5, 6};
    int target = 7;
    int len  = sizeof(nums) / sizeof(nums[0]);
    int new_len_number  = serchInsert(nums,len,target);
    printf("nuw len number = %d\n",new_len_number);
    printf("array = ");
    for(int i = 0 ; i< new_len_number;i++){
        printf("%d\n",nums[i]);
    }
    printf("\n");
    return 0;

}