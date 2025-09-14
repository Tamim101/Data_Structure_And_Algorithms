#include<stdio.h>
#include<stdlib.h>
int climbStairs(int n){
   if (n <= 2){
    return n;
   }
   int max_value = 1;
   int min_value = 2;
   int total_value;
   for(int i = 3; i <= n; i++){
    // total = (n + 10)/ 10;
    // equation of this problem f(n) = (n -1) = (n -2)
    total_value = (n-1)+(n-2);
    // max_value = min_value;
    // min_value = total_value;
    // printf("data = %d\n",min_value);
   }
   return total_value;
}
int *bucket(int array,int len,int right,int left){
   for(int i = 0; i < n; i++){
      bucket[i] = (int *) malloc(size_of *(int(len+1)));
      int count[i] = 0;
   }

}

int main(){
     int n = {4};
     climbStairs(n);
     printf("data = %d",climbStairs(n));
     for(int i = 3; i < n;i++){
      printf("data %d\n",climbStairs(n));
     }
     return 0;
}





