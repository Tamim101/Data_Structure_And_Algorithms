#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* convert(char* s, int numRows) {
    if(numRows == 1){
        printf("%s",&s);
        return 0;
    }
    int len = strlen(s);
    int row[numRows][len];
    char *bucket[numRows];
    int count[numRows];
    for(int i = 0; i < numRows; i++){
        bucket[i] = (char*)malloc((sizeof(char)*(len+1)));
        count[i] = 0;
    }
    int current_row = 0;
    int going_row = 1;
    for(int i = 0; i < len;i++){
        if(row[current_row] +i){

        }else if(row[current_row -1]){

        }else(row[current_row == 0]){

        }
    } 
    current_row ++;
    going_row --;
    return 0;


    
}
int main(){
    char strings[] = "abcdefg";
    int numrows = 2;
    for(int i = 0; i < numrows;i++){
        printf("data = %c\n",strings[i]);
    }
    convert(strings,numrows);
    for(int i = 0; i < numrows;i++){
        printf("data = %c\n",strings[i]);
    }
    return 0;
}