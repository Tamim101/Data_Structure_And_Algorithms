#include<stdio.h>
#include<string.h>
int length_of_last_world(char* s){
    int i,j;
    for (i = 0; s[i] != '\0';i++){
    }
    return i;
}
int main() {
    char *str = "hello";
    int len = length_of_last_world(str);
    printf("Length of '%s' is %d\n", str, len);
    return 0;
}