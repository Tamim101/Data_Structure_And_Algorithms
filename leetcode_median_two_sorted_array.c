#include<stdio.h>
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int result[nums1Size + nums2Size];
    int k = 0;
    for(int i = 0; i < nums1Size; i++){  // copy number 1 array
        result[k++] = nums1[i];
    }
    for(int j = 0; j< nums2Size; j++){  // copy number 2 array
        result[k++] = nums2[j];
    }
    for(int i = 0; i < nums1Size + nums2Size; i++){
        printf("%d\n",result[i]);

    }
    int main_result = (nums1Size + nums2Size);   // 1234 marged array
    float mid;
    if(main_result % 2 == 0){
        mid =  (result[main_result / 2 -1] + result[main_result /2]) / 2.0000;
       
    }else{
        mid = (result[main_result /2]-1);
    }
    printf("result = %d\n",main_result);
    return mid;


}
int main(){
    int arr1[] = {};
    int arr2[] = {1};
    int len1 = 0;
    int len2 = 1;
    int len = sizeof(arr1) / sizeof(arr2);
    printf("len = %d\n",len);
    double call_array = findMedianSortedArrays(arr1,len1,arr2,len2);
    printf("Median = %.5f\n", call_array);

    return 0;

}
# include<stdio.h>
double array_marged_impliment(int* array1, int arraySize1, int* array2, int arraySize2){
    int result[arraySize1 + arraySize2]; // length number added 
    int key = 0;   // key value 0
    for(int i = 0; i < arraySize1; i++){    // copy the first number 
        result[key++] =  array1[i];
    }
    for(int j = 0; j < arraySize2; j++){     // copy the secound number 
        result[key++] = array2[j];

    }
    for (int i = 0; i < arraySize1 + arraySize2; i++){ // number1 and number 2 are added 
    }
    int main_array = result[arraySize1 + arraySize2];
    float mid ;
    if(main_array % 2 == 0){
        mid = (result[main_array /2 -1] + result[main_array /2]) / 2.0000;
    }else{
        mid = (result[main_array /2] -1);
        printf("%d",mid);
    }
    return mid;

}
int main(){
    int array1[] = {1,3,5};
    int array2[] = {2,3};
    int arraySize1 = 3;
    int arraySize2 = 2;
    int call_array = array_marged_impliment(array1,arraySize1,array2,array2);
    printf("result = %d",call_array);
    return call_array;
}