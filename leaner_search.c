//LEANER SCARCH INPUT AND OUTPUT

#include <stdio.h>
#include <stdlib.h>  // for abs()

int main() {
    int num[100];
    int n,x;
    int i,found =-1;
     // Get number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Get the elements
    printf("Enter %d numbers: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }
    printf("ENTER NUMBER TO SCARCH =");
    scanf("%d",&x);
    for(int i=0;i<n;i++){
        if (num[i]==x){
            found = i;
            break;
        }
    }
    if (found!= -1){
        printf("number found at index %d\n",found);
    }else{
        printf("Number not found.\n");
    }
    return 0;
   
}
//MAIN CONSEPT DATA USE THE LEAD CODE OR HAKER RANK TIME COMPLEXCITY O(n)
int linear_search(int A[],int n,int x){
    int i;
    for (i=0;i<n;i++){
        if (A[i]==x){
            return i;
        }
    }
    return -i;
} 