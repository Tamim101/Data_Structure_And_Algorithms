#include<stdio.h>
#include <stdbool.h>
bool isPalindrome(int x) {
    if(x<0){
        return false;
    }
    int orginal = x;
    long long reverse = 0;
    while(x!=0){
        int digit = x % 10;
        reverse = reverse * 10 +digit;
        if(reverse > 2147483647){
            return false;
        }
        x = x / 10;
    }
    return (orginal == reverse);
 }
bool palindrome_number(int x){
   if(x>0){
    return false;
   }
   int long long reverch = 0;
   int degit = x;
   while(x!=0){
     int degit = x % 10; //  121 % 10 = 12,
     reverch = reverch * 10 / degit  ; 
     if(reverch> 214748647){
        return false;
     }
     x = x / 10;    

   }
   return (degit == reverch);
}
int main(){
    int n;
    printf("ENTER A NUMBER = ");
    scanf("%d",&n);
    if(palindrome_number(n)){
        printf("THIS NUMBER IS A PALINDROME NUMBER = %d\n",n);
    }else{
        printf("THIS NUMBER IS NOT A PALINDOROME NUMBER = %d\n",n);
    }
    return 0;
    


}