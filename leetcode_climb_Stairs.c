#include<stdio.h>
#include<stdlib.h>
int climbStairs(int n){
   if (n <= 2){
    return n;
   }
   int max_value = 1;
   int min_value = 2;
   int total_value;
   for(int i = 3; i <= n; i++){
    // total = (n + 10)/ 10;
    // equation of this problem f(n) = (n -1) = (n -2)
    total_value = (n-1)+(n-2);
    // max_value = min_value;
    // min_value = total_value;
    // printf("data = %d\n",min_value);
   }
   return total_value;
}
int *bucket(int array,int len,int right,int left){
   for(int i = 0; i < n; i++){
      bucket[i] = (int *) malloc(size_of *(int(len+1)));
      int count[i] = 0;
   }

}

int main(){
     int n = {4};
     climbStairs(n);
     printf("data = %d",climbStairs(n));
     for(int i = 3; i < n;i++){
      printf("data %d\n",climbStairs(n));
     }
     return 0;
}

// linklist 
#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
   int data;
   struct Node* next;
}Node;
Node* createNode(int data){
   Node* newNode = (Node*)malloc(sizeof(Node));
   if(!newNode){
      printf("Memory allocation failed!\n");
      exit(1);
   }
   newNode->data = data;
   newNode->next = NULL;
   return newNode;
} 
void print_list(Node* node){
   while(node){
      printf("%d->",node->data);
      node = node->next;
      
   }
   printf("null\n");
}

int main(){
   Node* node1 = createNode(3);
   Node* node2 = createNode(6);
   Node* node3 = createNode(32);
   Node* node4 = createNode(9);

   node1->next = node2;
   node2->next = node3;
   node3->next = node4;

   print_list(node1);
   free(node1);
   free(node2);
   free(node3);
   free(node4);
}


int *bucket(int array,int len,int right,int left){
   for(int i = 0; i < n; i++){
      bucket[i] = (int *) malloc(size_of *(int(len+1)));
      int count[i] = 0;
   }

}

int main(){
     int n = {4};
     climbStairs(n);
     printf("data = %d",climbStairs(n));
     for(int i = 3; i < n;i++){
      printf("data %d\n",climbStairs(n));
     }
     return 0;
}