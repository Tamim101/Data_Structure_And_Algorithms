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
int insert_data(int nums[],int length, int key,int capacity){

}