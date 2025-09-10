#include<stdio.h>
#include<stdlib.h>
int reverse(int x){
   int rev_number = 0;
   while(x>0){
      rev_number = rev_number * 10 + x % 10;
      x = x / 10;
   }
   return rev_number;
}
int main(){
    int x = 1320;
    printf("data1 %d",reverse(x));
    return x;
}