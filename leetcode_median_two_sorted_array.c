#include<stdio.h>
#include<stdlib.h>
int compact(const void *a, const void *b){
    return (*(int *)a - *(int *)b);
}
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int result = nums1Size + nums2Size ;
    int total[result];
    int k = 0;
    for(int i = 0; i < nums1Size; i++){  // copy number 1 array
        total[k++] = nums1[i];
    }
    for(int j = 0; j< nums2Size; j++){  // copy number 2 array
        total[k++] = nums2[j];
    }
    for(int i = 0; i < nums1Size + nums2Size; i++){
        printf("%d\n",total[i]);

    }
    qsort(total,result,sizeof(int),compact);
  // 1234 marged array
    double mid;
    if(result % 2 == 0){
        mid = (total[result / 2 -1] + total[result /2]) / 2.0000;
       
    }else{
        mid = (total[result /2]);
    }
    printf("result = %d\n",mid);
    return mid;


}
int main(){
    int arr1[] = {1,3};
    int arr2[] = {2};
    int len1 = 2;
    int len2 = 1;
    int len = sizeof(arr1) / sizeof(arr2);
    printf("len = %d\n",len);
    double call_array = findMedianSortedArrays(arr1,len1,arr2,len2);
    printf("Median = %.5f\n", call_array);

    return 0;

}
// # include<stdio.h>
// double array_marged_impliment(int* array1, int arraySize1, int* array2, int arraySize2){
//     int result[arraySize1 + arraySize2]; // length number added 
//     int key = 0;   // key value 0
//     for(int i = 0; i < arraySize1; i++){    // copy the first number 
//         result[key++] =  array1[i];
//     }
//     for(int j = 0; j < arraySize2; j++){     // copy the secound number 
//         result[key++] = array2[j];

//     }
//     for (int i = 0; i < arraySize1 + arraySize2; i++){ // number1 and number 2 are added 
//     }
//     int main_array = result[arraySize1 + arraySize2];
//     float mid ;
//     if(main_array % 2 == 0){
//         mid = (result[main_array /2 -1] + result[main_array /2]) / 2.0000;
//     }else{
//         mid = (result[main_array /2] -1);
//         printf("%d",mid);
//     }
//     return mid;

// }
// int main(){
//     int array1[] = {1,3,5};
//     int array2[] = {2,3};
//     int arraySize1 = 3;
//     int arraySize2 = 2;
//     int call_array = array_marged_impliment(array1,arraySize1,array2,array2);
//     printf("result = %d",call_array);
//     return call_array;
// }

// 56789
#include<stdio.h>
int main(){
    int main_array[] = {5,8,2,5,1,9,55,8,44};
    int lenght_array = sizeof(main_array) / sizeof(main_array[0]);
    for(int i = 0; i < lenght_array -1;i++){
        int main_index = i;
        for(int j = i+1; j < lenght_array;j++){
            if(main_array[j] < main_array[main_index]){
                main_index = i;
            }
        }
        int min_value = main_index;
        for(int k = 0; k > i; k--){
            main_array[k] = main_array[k-1];
        }
        main_array[i] = min_value;
    }
    printf("sortade array");
    for(int i = 0; i< lenght_array;i++){
        printf("array %d",main_array[i]);

    }
    return 0;
}

int main(){
    int array1[] = {1,4,3,55,221,12,44,5};
    int length_array = sizeof(array1) / sizeof(array1[0]);
    for(int i  = 0; i < length_array ; i++){
        int main_index = i;
        for(int j = i + 1; j < length_array; j++){
            if(array1[j] < array1[main_index]){
                main_index = j;
            }
        }
        int temp = array1[i];
        array1[i] = array1[main_index];
        array1[main_index] = temp;
    }
    for(int k = 0; k < length_array; k++){
        printf("%d",array1[k]);
    }
    return 0;
}

int main(){
    int array_index[] = {1,5,3,2,6};
    int len_array_index = sizeof(array_index) / sizeof(array_index[0]);
    for(int i = 0; i < len_array_index ; i++){
        int instart_sort = i;
        int max_value = array_index[i];
        int j = i - 1;
        while(j >= 0 && array_index[j] < max_value){
            array_index[j + 1] = array_index[i];
            instart_sort = j;
            j--;
        }

    }
    for(int i = 0; i < len_array_index;i++){
        printf("%d",array_index[i]);
    }
    return 0;
}

// quick sort 
void quick_sort(int array[],int low , int high);
int next_array(int array[],int low, int high);
int main(){
    int array[] = {3,4,22,5,55,43,2};
    int length = sizeof(array) / sizeof(array[0]);
    quick_sort(array,0,length - 1);
    printf("after");
    for(int i = 0; i < length; i++){
        printf("quick sort %d", array[i]);
    }
    return 0;
}
void quick_sort(int array[],int low, int high){
    if(low < high){
        int main_array = next_array(array,low,high);
        quitck_sort(array,low,main_array - 1);
        quick_sort(array,main_array -1,high);
    }
}
int next_array(int array[],int low,int high){
    int high_value = array[high];
    int low_value = low -1;
    for(int j = low; j < high ; j++){
        if(array[j]<= high_value){
            int temp = array[low_value];
            array[low_value] = array[j];
            array[j] = temp;

        }
        
    }
    int temp = array[low_value -1];
    array[low_value + 1] = array[high];
    array[high] = temp;
    return low_value + 1;

}