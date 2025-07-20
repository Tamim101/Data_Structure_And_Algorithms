#include<stdio.h>
#include<string.h>
#include<stdbool.h>

bool isValid(char* s) {
   char stack[1000];
   int top = -1;   
   for(int i=0;s[i] != '\0';i++){
    char c = s[i];
    printf("c = %c\n",c);
    if(c == '(' || c == '[' || c == '{'){
        stack[++top] = c;
        printf("stack c = %c\n",c);
    }else{
        if(top == -1){
        return false;
    }
        char last = stack[top--]; // Pop
            if ((c == ')' && last != '(') ||
                (c == ']' && last != '[') ||
                (c == '}' && last != '{')) {
                return false;
           }
    }
   }
   return top == -1;
}
int main(){
   char input[100];
   printf("ENTER PARENTHESES = ");
   scanf("%s",input);
   if(isValid(input)){
    printf("Valid\n");
   }
   else{
    printf("invalid\n");
   }
}


