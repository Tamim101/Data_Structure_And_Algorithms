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
