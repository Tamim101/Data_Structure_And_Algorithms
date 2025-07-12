#include<stdio.h>
int romanToInt(char* s) {
   int value(char c){
    switch(c){
        case 'I':return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
   } 
   int total = 0;
   for(int i = 0; s[i]!= '\0';i++){
    int current_value = value(s[i]); // now current value C = 100 
    int next_value = value(s[i+1]);
       printf("%d",next_value);  //now next value cI this type intger incriment
    if(current_value < next_value){
        total += next_value - current_value ;
        printf("%d\n",total); // 1000 -100 =900 then ans is 900 when loop 1 this time 1000-100 =900 so total = 1000+ 900 = 1900
        i++; //then i = i+1 ,i incriment  
    }else{
        total += current_value;
    }
   }
   return total;
}
int main() {
    char roman[20];
    printf("Enter Roman Numeral: ");
    scanf("%s", roman);

    int result = romanToInt(roman);
    printf("Integer: %d\n", result);
    return 0;
}