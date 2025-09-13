#include<stdio.h>
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

int main(){
     int n = {4};
     climbStairs(n);
     printf("data = %d",climbStairs(n));
     for(int i = 3; i < n;i++){
      printf("data %d\n",climbStairs(n));
     }
     return 0;
}





