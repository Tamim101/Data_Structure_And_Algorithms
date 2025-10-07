#include <stdio.h>
#include <ctype.h>   // For isspace, isdigit
#include <limits.h>  // For INT_MIN, INT_MAX

int myAtoi(char* s) {
    if (s == NULL) {
        return 0;
    }
    
    int i = 0;
    int sign = 1;
    long result = 0; 
    
    // Skip leading whitespace
    while (s[i] != '\0' && isspace((unsigned char)s[i])) {
        i++;
    }
    if (s[i] == '+' || s[i] == '-') {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }
    while (s[i] != '\0' && isdigit((unsigned char)s[i])) {
        result = result * 10 + (s[i] - '0');
        if (result > INT_MAX) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }
        i++;
    }
    
    result *= sign;
    if (result > INT_MAX) {
        return INT_MAX;
    }
    if (result < INT_MIN) {
        return INT_MIN;
    }
    
    return (int)result;
}