#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
// int reverse(int x){
//    int sing = 1;
//    long rev_number = 0;
//    if(x<0){
//      sing = -1;
//      x = x * sing;
//    }
//    while(x>0){
//       int digit = x % 10;
//       if (rev_number > (INT_MAX - digit) / 10) {
//             printf("0");
//             return 0;
//       }
//       rev_number = rev_number * 10 + digit;
//       x = x / 10;   
//    }
//    return (int)(rev_number * sing);

   
// }
// int main(){
//     int x = -1534236469;
//     printf("data %d",reverse(x));
//     return x;
// }
int reverse(int x){
   long rev_number = 0;
   while(x != 0){
      int digit = x% 10;
      x = x / 10;
      if(rev_number > INT_MAX /10 || (rev_number == INT_MAX /10 && digit > 7)){
         return 0;
      }
      if(rev_number < INT_MIN /10 || (rev_number == INT_MIN /10 && digit < -8)){
         return 0;
      }
      rev_number = rev_number * 10 + digit;
   }
   return (int)rev_number;
}
int main(){
    int x = 132;
    printf("data %d",reverse(x));
    return 0;
}