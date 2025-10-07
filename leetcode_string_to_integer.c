#include<stdio.h>
#include<limits.h>
int myAtoi(char* s){
    if(s == NULL){
        return ;
    }
    int j = 0;
    int sign = 1;
    while(s[i] != '\0'){
        if(!isspace((unsigned)s[i])){
            s[j] = s[i];
        }
        i++;
    }
    s[j] = '\0';
    if(s[i] == '+'|| s[i] == '-'){
        sign = (s[i]=='-')? -1: 1;
        i++;
    }
    while(isdigit((unsigned)s[i])){
        int result = result * 10 + (s[i] - '0');
        if(result > INT_MAX){
            return (sign ==1)? INT_MAX: INT_MAX;
        }
        i++;
    }
    result *= sign;
    return (int)result;
}