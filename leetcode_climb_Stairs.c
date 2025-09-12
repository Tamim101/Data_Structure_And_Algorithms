#include<stdio.h>
int climbStairs(int n){
    int len;
    while(n>0 && n <= 45){
        int total = (n + 10) / 10;
        int lon = total+1;
        int final = lon+1;
        if(final== n){
            
            break;
        }
    
    }
    return n;
}

int main(){
     int n = {54};
     climbStairs(n);
     printf("data = %d",climbStairs(n));
     return 0;
}





