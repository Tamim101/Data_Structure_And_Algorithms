#include<stdio.h>
#include<string.h>
int strStr(char* haystack, char* needle){
    int i;
    if(strcmp(haystack,needle)== 0){
        printf("same : 0\n");
        return 0;
    }else{
        printf("same : -1");
        return -1;
    }

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