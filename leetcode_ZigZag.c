#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void init_bucket(char **bucket, int *count, int numRows,int len ){
    for(int i = 0; i < numRows;i++){
        bucket[i] = (char *)malloc(sizeof(char) * (len + 1));         // i create a bucket just like a matrix row
        count[i] = 0;

    }
}
void fill_bucket(char* s, char **bucket, int *count , int numRows){
    int len = strlen(s);
    int current_row = 0;
    int ongoing_row = 1;
    for(int i = 0; i < len; i++){
        bucket[current_row][count[current_row]++] = s[i];  
        if(current_row == numRows -1){           // row inishish  up ^ 
            ongoing_row = 0;
        }
        else if(current_row == 0){              // row inishinsh down 
                ongoing_row = 1;
        }
        current_row +=ongoing_row ? 1:-1;
        
    }
}
char *joind_bucket(char **bucket, int *count, int numRows){
    char *result = (char*)malloc(1000);
    result[0] = '\0';
    for(int i = 0; i < numRows; i++){
        bucket[i][count[i]] = '\0';  // all terminal null
        strcat(result, bucket[i]);   // string create
    
    }
    return result;
}
char* convert(char* s, int numRows) {
    if(numRows == 1){
        printf("%s",s);
        return s;
    }
    char *bucket[numRows];
    int count[numRows];
    int len = strlen(s);
    init_bucket(bucket,count,numRows,len);  //call init_bucket
    fill_bucket(s,bucket,count,numRows);    //call fill_bucket
     char *result = joind_bucket(bucket, count, numRows);

    // Free memory for buckets
    for(int i = 0; i < numRows; i++) {
        free(bucket[i]);
    }

    return result;
    joind_bucket(bucket,count,numRows);
    return result;

}

int main(){                               // main funshion in zigzag
    char strings[] = "abcde";
    int numrows = 3;
    char *result = convert(strings,numrows);
    printf("ZigZag data  = %s\n",result);
    free(result);
    return 0;



}




