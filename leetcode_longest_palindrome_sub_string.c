#include<stdio.h>
#include<string.h>
int longestPalindrome(char s[]) {
    int length = strlen(s);
    printf("length = %d\n",length);
    int start = 0;
    int end = length -1;
    while(start < end){
        if(s[start]!= s[end]){
            return 0;
        }
        start++;
        end--;
        return 1;
    }

    int max_len = 0;
    int save_len = 0;
    for(int i = 0; i <= s; i++){
        for(int j = i; j <= s; j--){
            if((s,i,j) && (j-i+1) < max_len){
                max_len = j-i+1;
                printf("max_len = %c\n", max_len);

                save_len = i;
            }
            

        }
    }
    for(int k = 0; k < save_len + max_len ; k++){
        printf("main array %c\n", s[k]);
    }
    printf("\n");

    return 0;
}
int main() {
    char s[] = "babad";
    if(longestPalindrome(s)){
        printf("[%s] is a palindrome\n", s);
    } else {
        printf("[%s] is not a palindrome\n", s);
    }
    return 0;
}

// array = 1,3,4,5,6,3,2,1,2
//   output = 1,1,2,2,3,3,4,5,6
#include<stdio.h>
int counting_sort(int array[],int lenght){
    int array[] = {1,3,4,5,6,3,2,1,2};
    int length = sizeof(array) / sizeof(array[0]);
    int max_len=0;
    for(int i = 1; i < lenght; i++){
        if(array[i]> max_len){
            max_len = array[i];
        }
    }
    int count[max_len + 1];
    for(int i = 0; i <= count;i++){
       array[i] = 0;
    }
    for(int i = 0; i < lenght;i++){
        count[array[i]]++;
    }
    int index = 0;
    for(int i = 0 ; i <= max_len; i++){
       while(count[i]>0){
         array[index++] = i;
         count[i]--;
       }
    }
}

