//BINARY SEARCH
#include <stdio.h>

int main() {
    int num[100];
    int n, x, i;
    int left, right, mid;
    int found = -1;

    // Get number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Get the elements
    printf("Enter %d sorted numbers: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }

    // Ask for number to search
    printf("Enter number to search: ");
    scanf("%d", &x);

    // Initialize search boundaries after reading n
    left = 0;
    right = n - 1;

    // Binary search
    while (left <= right) {
        mid = (left + right) / 2;

        if (num[mid] == x) {
            found = mid;
            break;
        }
        if (num[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (found != -1) {
        printf("Number found at index %d\n", found);
    } else {
        printf("Number not found.\n");
    }

    return 0;
}
// LEAD COODE AND HAKER RANK time complexcity log₂(n)
int binary_scarch(int A[],int n,int x){
    int left,right,mid;
    right = right -1;
    while(left<=right){
        mid = (left+right)/2;
        if (A[mid]==x){
            return mid;
        }
        if(A[mid]<x){
            left = mid + 1;
        }else{
            right = mid -1;
        }
    }
    return -1;
}
