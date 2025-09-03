// #include<stdio.h>
// #include<string.h>
// int longestPalindrome(char s[]) {
//     int length = strlen(s);
//     printf("length = %d\n",length);
//     int start = 0;
//     int end = length -1;
//     while(start < end){
//         if(s[start]!= s[end]){
//             return 0;
//         }
//         start++;
//         end--;
//         return 1;
//     }
//     int max_len = 0;
//     int save_len = 0;
//     for(int i = 0; i <= s; i++){
//         for(int j = i; j <= s; j--){
//             if((s,i,j) && (j-i+1) < max_len){
//                 max_len = j-i+1;
//                 printf("max_len = %c\n", max_len);

//                 save_len = i;
//             }
//         }
//     }
//     for(int k = 0; k < save_len + max_len ; k++){
//         printf("main array %c\n", s[k]);
//     }
//     printf("\n");

//     return 0;
// }
// int main() {
//     char s[] = "babad";
//     if(longestPalindrome(s)){
//         printf("[%s] is a palindrome\n", s);
//     } else {
//         printf("[%s] is not a palindrome\n", s);
//     }
//     return 0;
// }

// // array = 1,3,4,5,6,3,2,1,2
// //   output = 1,1,2,2,3,3,4,5,6
// #include<stdio.h>
// void counting_sort(int array1[],int lenght){
//     int max_len=0;
//     for(int i = 1; i < lenght; i++){
//         if(array1[i]> max_len){
//             max_len = array1[i];
//         }
//     }
//     int count[max_len + 1];
//     for(int i = 0; i <= max_len;i++){
//        count[i] = 0;
//     }
//     for(int i = 0; i < lenght;i++){
//         count[array1[i]]++;
//     }
//     int index = 0;
//     for(int i = 0 ; i <= max_len; i++){
//        while(count[i]>0){
//          array1[index++] = i;
//          count[i]--;

//        }
//     }
 

// }
// int main(){
//     int array1[] = {13,34,756765,2,233,77,99,00,33,1,88,00,7,0,-0,7,767,998,32432,8};
//     int len_size = sizeof(array1) / sizeof(array1[0]);
//     counting_sort(array1,len_size);
//      printf("Sorted array: ");
//     for(int i = 0; i < len_size;i++){
//         printf(" %d ",array1[i]);
//     }
//     printf("\n");
//     return 0;
// }

// // radix sort 

// #include<stdio.h>
// #include<stdlib.h>
// #define SIZE 100
// void radix_sort_array(int data[], int len_size){
//     int max_value = data[0];
//     for(int i = 1; i < len_size; i++){   // find the large data in the array
//         if(data[i] > max_value){
//             max_value = data[i];
//         }
//     }
//     int equation_exc = 1;
//     int *bucket [10];
//     for(int i = 0; i < 10;i++){
//        bucket[i] = (int*)malloc(sizeof(int) * len_size);  // make a 10 bucket
//     }
//     int counts[10] = {0};
//     while(max_value / equation_exc > 0){
//         for(int i = 0; i < len_size;i++){
//             int bucket_data_limit = (data[i] / equation_exc) % 10;
//             bucket[bucket_data_limit][counts[bucket_data_limit]] = data[i];
//             counts[bucket_data_limit]++;
//         }
//         int position_data = 0;
//         for(int i = 0; i < 10;i++){
//             for(int j = 0; j < counts[i];j++){
//                 data[position_data] = bucket[i][j];
//                 position_data ++;
//             }
//             counts[i]=0;

//         }
//         equation_exc *= 10;

//     }
//     for(int i = 0; i < 10; i++){
//         free(bucket[i]);
//     }


// }
// int main(){
//     int data[] = {123,35,23,54,32,34534,65768,4353,24234,23231,3345,234234,2313,34235};
//     int len = sizeof(data)/ sizeof(data[0]);
//     printf("orginal array = ");
//     for(int i = 0; i < len; i++){
//         printf(" %d ",data[i]);
//     }
//     printf("\n");
//     radix_sort_array(data,len);
//     printf("redix array = ");
//     for(int i = 0; i < len; i++){
//         printf(" %d ",data[i]);
//     }
//     printf("\n");
//     return 0;

// }

#include<stdio.h>

void marged_sort(double arr[],int start , int end);
void marged_array(double arr[],int start, int mid,int end);
int main(){
    int array[] = {1,44,3,4,66,7,8,5,4,3,667,665,444};
    int length = sizeof(array) / sizeof(array[0]);
    for(int i = 0; i < length; i++){
        printf("after array = %d",array[i]);
    }
    marged(array,0,length-1);
    printf("before\n");
    for(int i = 0; i < length; i++){
        printf("sorted array %d",array[i]);
    }    
}
void marged_sort(double arr[],int start,int end){
    if(start < end){
        int mid = (start + end) / 2;
        marged_sort(arr,start,end);
        marged_sort(arr,mid+1,end);
        marged_sort(arr,start,mid,end);
    }
}
void marged_sort(double arr[],int start,int end){
    if(start < end){
        int mid = (start + end) / 2;
        marged_sort(arr,start,end);
        marged_sort(arr,mid+1,end);
        marged_sort(arr,start,mid,end);
    }
}
//
void marged_sort(double arr[],int start,int end){
    if(start < end){
        int mid = (start + end) / 2;
        marged_sort(arr,start,end);
        marged_sort(arr,mid+1,end);
        marged_sort(arr,start,mid,end);
    }
}
void marged_sort(double arr[],int start,int end){
    if(start < end){
        int mid = (start + end) / 2;
        marged_sort(arr,start,end);
        marged_sort(arr,mid+1,end);
        marged_sort(arr,start,mid,end);
    }
}
int main(){
    int array[] = {1,44,553,23,55};
    int length  = sizeof(array) / sizeof(array[0]);
    for(int i = 0; i < length; i++):
        printf("%d",array[i]);

}   
    printf("data array apply");
    for(int j = 0; j < length; j++){
        printf("data array done",array[i]);
    }





