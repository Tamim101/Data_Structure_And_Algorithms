#include <stdio.h>

struct ListNode {
      int val;
      struct ListNode *next;
 };
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode dummy;  
    struct ListNode* current = &dummy;   
    while(list1 != NULL && list2 != NULL){
        if(list1->val <= list2->val){
            current->next = list1;
            list1 = list1 -> next;
        }else{
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;                               
    }
    if(list1 != NULL){
        current-> next = list1;   

    }
    if(list2 != NULL){
        current-> next = list2;
    }
    return dummy.next ;

}



void Bubble_sort(int arr[],int n){
    for(int i = 0; i < n-1;i++){
        for(int j = 0; j < n-i-1;j++){
           if(arr[j]>arr[j+1]){
            int temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
           }
        }
    }
}


void marge_sort(int arr1[],int arr2[],int list_size1,int list_size2,int marge[]){
    int i = 0;
    int j = 0;
    int k = 0;
    int t ;
    while(i<list_size1 && j < list_size2){
        if(arr1[i]<=arr2[j]){
            marge[k++] = arr1[i++];
        }else{
            marge[k++] = arr2[j++];  
        }   
    }
    while(i<list_size1){
        marge[k++] = arr1[i++];
        
    }
    while(j<list_size2){
        marge[k++] = arr2[j++];
    }
}
int main(){
    int arr1[] = {1,4,3,2};
    int arr2[] = {9,8,7};
    int list_size1 = sizeof(arr1) / sizeof(arr1[0]);
    int list_size2 = sizeof(arr2) / sizeof(arr2[0]);
    int marge[list_size1 + list_size2];
    Bubble_sort(arr1,list_size1);
    Bubble_sort(arr2,list_size2);
    marge_sort(arr1,arr2,list_size1,list_size2,marge);
    printf("marge sort this array = \n");
    for(int i=0; i < list_size1+list_size2;i++){
        printf(" %d ",marge[i]);
    }
    printf("\n");
    return 0;

}
