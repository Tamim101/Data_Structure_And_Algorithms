//BUBLE SORT 
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
       for(int j=0;j<n-i-1;j++){
          if(num[j]>num[j+1]){
            temp = num[j];
            num[j] = num[j+1];
            num[j+1] = temp;
          }
       }
    }
    printf("Sorted array: ");
    for(i = 0; i < n; i++){
        printf("%d ", num[i]);
    }
    printf("\n");
    return 0;

}
// LEAD CODE OR HAKER RANK 
int bubble_sort(int A[],int n){
    int i,j,temp;
    for (i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if (A[j]>A[j+1]){
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
    return 0;
}