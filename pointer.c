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

void incriment(int *p){
    *p = *p+1;
}
int main(){
    int a = 10;  // global
    incriment(&a);
    printf("a = %d",a);
}
