#include <stdio.h>
#include <string.h>
int hash_value(const char* value){
    int sum = 0;
    for(int i = 0; i < strlen(value);i++){
        sum += (int)value[i];
    }
    return sum % 10;
}

int main(){
    char value[] = "adfc";
    printf("%s is the hash asci number: %d",value,hash_value(value));
    return 0;
}
#include <stdio.h>
#include <string.h>
int hash_value(const char* value){
    int sum = 0;
    for(int i = 0; i < strlen(value);i++){
        sum += (int)value[i];
    }
    return sum % 10;
}

int main(){
    char value[] = "adfc";
    printf("%s is the hash asci number: %d",value,hash_value(value));
    return 0;
}

#include <stdio.h>
#include <string.h>
int hash_value(const char* value){
    int sum = 0;
    for(int i = 0; i < strlen(value);i++){
        sum += (int)value[i];
    }
    return sum % 10;
}

int main(){
    char value[] = "adfc";
    printf("%s is the hash asci number: %d",value,hash_value(value));
    return 0;
}
#include <stdio.h>
#include <string.h>
int hash_value(const char* value){
    int sum = 0;
    for(int i = 0; i < strlen(value);i++){
        sum += (int)value[i];
    }
    return sum % 10;
}

int main(){
    char value[] = "adfc";
    printf("%s is the hash asci number: %d",value,hash_value(value));
    return 0;
}
#include <stdio.h>
#include <string.h>

char* myHashSet[10] = {NULL, "Jones", NULL, "Lisa", NULL, "Bob", NULL, "Siri", "Pete", NULL};

int hashFunction(const char* value) {
    int sumOfChars = 0;
    while (*value) {
        sumOfChars += (int)*value;
        value++;
    }
    return sumOfChars % 10;
}

int contains(const char* name) {
    int index = hashFunction(name);
    if (myHashSet[index] != NULL && strcmp(myHashSet[index], name) == 0) {
        return 1; // True
    }
    return 0; // False
}

int main() {
    printf("'Pete' is in the Hash Set: %s\n", contains("Pete") ? "true" : "false");
    return 0;
}

// C