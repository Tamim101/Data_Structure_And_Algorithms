#include<stdio.h>
char* longest_common_prefix(char** strs, int strssize){
    int i,j,n;
    for(i=0;i<n;i++){
        strssize = i;
        for(j=i+1;j<n;j++){
            if(strs[j]<strs[strssize]){
                strssize = j;
            }
        }
        if(strssize != i){
            int temp = strssize[i];
        }
    }
}