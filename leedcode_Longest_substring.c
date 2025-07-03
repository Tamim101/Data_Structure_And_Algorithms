#include <stdio.h>
#include <stdlib.h>

int leanth_substring(char* s){
    int last_index[256];
    for(int i = 0;i<256;i++){
        last_index[i] = -1;
    }
    int maxlen = 0;
    int start = 0;
    for(int i = 0;s[i] != '\0';i++){
        char ch = s[i];
        if(last_index[(unsigned char)ch] >= start){
            start = last_index[(unsigned char)ch] +1;
        }
        last_index[(unsigned char)ch] = i;
        int currlen = i - start +1;
        if(currlen > maxlen){
            maxlen = currlen;
        }
    }
    return maxlen;
}
int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);  

    int result = leanth_substring(str);
    printf("Length of longest substring without repeating characters: %d\n", result);
    return 0;
}