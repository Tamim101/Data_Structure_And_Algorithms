//Selection Sort 1 5 7 38 9 5
#include<stdio.h>
int main(){
    int num[100];
    int n,i;
    int index_min,temp;
    printf("ENTER THE ELEMENT = ");
    scanf("%d",&n);
    printf("ENTER THE %d SORTED NUMBER = ",n);
    for(i=0;i<n;i++){
        scanf("%d",&num[i]);
    }
    for(i=0;i<n;i++){
        index_min = i;
        for(int j=i+1;j<n;j++){
            if(num[j]<num[index_min]){
                index_min = j;
            }
        }
        if (index_min != i){
            temp = num[i];
            num[i] = num[index_min];
            num[index_min] = temp;
        }
    }
    
    printf("Sorted array: ");
    for(i = 0; i < n; i++){
        printf("%d ", num[i]);
    }
    printf("\n");

    return 0;

}                                       

// LEAD CODE OR HAKER RANK  Selection Sort
int selection_sort(int A[],int i){
    int index_min;
    int n,j,temp;
    for (i=0;i<n;i++){
        index_min = i;      // 33 11 444
        for(j=i+1;j<n;j++){
           A[j] <A[index_min];
           index_min = j ;   //1
        }
    }
    if(A[index_min] != i){
        temp = A[i];
        A[i] = A[index_min];
        A[index_min] = temp;
    }
    return 0;
}