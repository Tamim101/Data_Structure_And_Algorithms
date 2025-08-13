#include<stdio.h>
#include<string.h>
int strStr(char* haystack, char* needle){
    int i;
    if(strcmp(haystack,needle)== 0){
        printf("same : 0\n");
        return 0;
    }
    int haystack_len = strlen(haystack);
    int needle_len = strlen(needle);
    for(int i = 0; i<=haystack_len - needle_len; i++){
        int j;
        for(j = 0; j < needle_len; j++){
            if(haystack[ i+j] !=needle[j]){
                break;
            }
        }
        if(j == needle_len){
            printf("same : %d\n", i);
            return i;
        }

    } 
     printf("same : -1\n");
     return -1;

}
int main(){
    char haystack[100];
    char needle[100];
    printf("enter the string =");
    scanf("%s",haystack);
    printf("enter the string =");
    scanf("%s",needle);
    strStr(haystack,needle);
    return 0;
}
