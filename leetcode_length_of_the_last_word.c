#include<stdio.h>
#include<string.h>
int length_of_last_world(char* s){
    int i,j;
    int last_length = 0;
    int current_length = 0;
    for (i = 0; s[i] != '\0';i++){
        if(s[i] != ' '){
          current_length++;
          last_length = current_length;
        }else{
            current_length = 0;
        }
    }
    return last_length;
}
int main() {
    char *str = "hello world now i have ";
    int len = length_of_last_world(str);
    printf("Length of '%s' is %d\n", str, len);
    return 0;
}

int main() {
    char *str = "hello world now i have ";
    int len = length_of_last_world(str);
    printf("Length of '%s' is %d\n", str, len);
    return 0;
}