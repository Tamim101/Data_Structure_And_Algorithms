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
    int main_result = (nums1Size + nums2Size);
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