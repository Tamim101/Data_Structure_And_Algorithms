//lead code or haker rank 
void insertion_sort(int A[],int n){
    int i,j,item;
    for (i=1;i<n;i++){
        item = A[i];    //item assin
        j = i-1;
        while(j>=0 && A[j]>item){
           A[j+1] = A[j];  //len number swap to j+1
           j = j-1;
    }
    A[i+1] = item;    //item is empity
    }
}

#include<stdio.h>
int main(){
    int num[100];
    int n,i,j;
    int item;
    printf("ENTER ELEMENT = ");
    scanf("%d", &n);

    printf("ENTER %d NUMBER = ", n);
    for(i=0;i<n;i++){
        scanf("%d",&num[i]);
    }
    for(i=0;i<n;i++){
        item = num[i];
        j = i-1;
        while(j>=0 && num[j]>item){
              num[j+1] = num[j];
              j = j-1;
        } 
        num[j+1] = item;     
    }
    
    printf("Sorted array: ");
    for(i = 0; i < n; i++){
        printf("%d ", num[i]);
    }
    printf("\n");
    return 0;
}
