#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TABLE_SIZE 10
typedef struct node{
    char* key;
    int value;
    struct node* next;
}node_t;
node_t* hash_table[TABLE_SIZE];
unsigned int hash(const char* key){
    unsigned int hash = 0;
    while(*key){
        hash = (hash* 31) + *key++;
    }
    return hash % TABLE_SIZE;
}
void insert(const char* key, int value){
    unsigned int index = hash(key);
    node_t* new_node = malloc(sizeof(node_t));
    new_node->key = strdup(key);
    new_node->value = value;
    new_node->next = hash_table[index];
    hash_table[index] = new_node;
    printf("= %d \n",new_node);
}
//fined the value into key
int* search(const char* key){
    unsigned int index = hash(key);
    node_t* current = hash_table[index];
    while(current){
        if(strcmp(current->key,key)==0){
            printf("current value = %d\n",&current->value);
            return &current->value;
        }
        current = current->next;
    }
    return NULL;
}
//free memory
void free_table(){
    for(int i = 0;i< TABLE_SIZE;i++){
        node_t* current = hash_table[i];
        while(current){
            node_t* temp = current;
            current = current->next;
            free(temp->key);
            free(temp);
        }
    }
}
int main() {

    insert("apple", 10);
    insert("banana", 20);
    insert("orange", 30);

    int* value = search("banana");
    if (value) {
        printf("Found: %d\n", *value);  
    } else {
        printf("Not found\n");          
    free_table();
    return 0;
 }
}