// #include <stdio.h>
// #include <string.h>
// int hash_value(const char* value){
//     int sum = 0;
//     for(int i = 0; i < strlen(value);i++){
//         sum += (int)value[i];
//     }
//     return sum % 10;
// }

// int main(){
//     char value[] = "adfc";
//     printf("%s is the hash asci number: %d",value,hash_value(value));
//     return 0;
// }
// #include <stdio.h>
// #include <string.h>
// int hash_value(const char* value){
//     int sum = 0;
//     for(int i = 0; i < strlen(value);i++){
//         sum += (int)value[i];
//     }
//     return sum % 10;
// }

// int main(){
//     char value[] = "adfc";
//     printf("%s is the hash asci number: %d",value,hash_value(value));
//     return 0;
// }

// #include <stdio.h>
// #include <string.h>
// int hash_value(const char* value){
//     int sum = 0;
//     for(int i = 0; i < strlen(value);i++){
//         sum += (int)value[i];
//     }
//     return sum % 10;
// }

// int main(){
//     char value[] = "adfc";
//     printf("%s is the hash asci number: %d",value,hash_value(value));
//     return 0;
// }
// #include <stdio.h>
// #include <string.h>
// int hash_value(const char* value){
//     int sum = 0;
//     for(int i = 0; i < strlen(value);i++){
//         sum += (int)value[i];
//     }
//     return sum % 10;
// }

// int main(){
//     char value[] = "adfc";
//     printf("%s is the hash asci number: %d",value,hash_value(value));
//     return 0;
// }
// #include <stdio.h>
// #include <string.h>

// char* myHashSet[10] = {NULL, "Jones", NULL, "Lisa", NULL, "Bob", NULL, "Siri", "Pete", NULL};

// int hashFunction(const char* value) {
//     int sumOfChars = 0;
//     while (*value) {
//         sumOfChars += (int)*value;
//         value++;
//     }
//     return sumOfChars % 10;
// }

// int contains(const char* name) {
//     int index = hashFunction(name);
//     if (myHashSet[index] != NULL && strcmp(myHashSet[index], name) == 0) {
//         return 1; // True
//     }
//     return 0; // False
// }

// int main() {
//     printf("'Pete' is in the Hash Set: %s\n", contains("Pete") ? "true" : "false");
//     return 0;
// }

//

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BUCKET_COUNT 10
#define MAX_STRING_LENGTH 256
typedef struct Node{
    char value[MAX_STRING_LENGTH];
    Struct Node* next;
}Node;
typedef struct {
    Node* bucket[BUCKET_COUNT];
}SimpleHashSet;
unsigned int hashFunction(const char* value){
    unsigned int hash = 0;
    while(*value){
        hash = (hash + *value++) % BUCKET_COUNT;
    }
    return hash;
}
void intHashSet(SimpleHashSet* set){
    for(int i = 0; i < BUCKET_COUNT; i++){
        set->bucket[i] = NULL;
    }
}
int hashSetContains(SimpleHashSet *set, const char *value){
    unsigned int index = hashFunction(value);
    Node *node = set->bucket[index];
    while(node != NULL){
        if(strcmp(node->value,value) == 0){
            return 1;
        }
        node = node->next;
    }
    return 0;

}