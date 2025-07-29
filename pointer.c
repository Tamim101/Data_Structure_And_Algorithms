#include<stdio.h>
int main(){
    int a = 1025;
    int *p;
    p = &a;
    printf("size of intger is %d bytes\n",sizeof(int));
    printf("Address = %d\n, value = %d\n",p,*p);
    printf("Address = %d, value = %d\n",p+1,*p+1);

    char *st0;
    st0 = (char*)p;
    printf("size of char is %d bytes\n",sizeof(char));
    printf("Address = %d\n, value = %d\n",st0,*st0);
    printf("Address = %d\n, value = %d\n",st0+1,*st0+1);
    return 0;
}
int main(){
  int x = 5;
  int* p = &x;
  *p = 6;
  int ** q = &p;
  int *** r = &q;
  printf("%d\n",*p);
  printf("%d\n",*q);
  printf("%d\n",**q);
  printf("%d\n",**r);
  printf("%d\n",***r);
  ***r  = 10;
  printf("x = %d\n",x);
  return 0;
}
#include<stdio.h>
int main(){
    int i = 0;
    for(i = 0 ; i<100;i++){
        int *sum = 0;
        sum += i;
        printf("sum = %d\n",&sum);
    }
    return 0;
}

#include<stdio.h>
int main(){
    int i = 0;
    for(i = 0 ; i<100;i++){
        int *q = 0;
        q += i;
        printf("sum = %d\n",&q);
    }
    return 0;
}
#include<stdio.h>
int sum_of_element(int A[]){
    int i,sum = 0;
    int size = sizeof(A) / sizeof(A[0]);
    for(i = 0; i< size; i++){
        sum += A[i];
        printf("sum2 = %d\n",sum);

    }
    printf("sum = %d\n",sum);
    return sum;
}
int main(){
    int A[] = {1,2,3,4,5};
    int total = sum_of_element(A);
    printf("sum of element = %d\n",total);
}

#include<stdio.h>
int main(){
    int arr[] = {100,200,3,4};
    printf("%d\n",&arr[0]);
    printf("%d\n",arr);
    printf("%d\n",&*(arr+1));
    printf("%d\n",arr[1]);
    return 0;
}