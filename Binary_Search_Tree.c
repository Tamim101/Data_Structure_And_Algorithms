#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* left;   //here struct is a node
    struct Node* right;
};
struct Node* create_node(int data){
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
void in_order(struct Node* root){
    if(root == NULL){
        return;
    }
    in_order(root->left);
    printf("%d",root->data);
    in_order(root->right);
}
void pre_order(struct Node* root){
    if(root == NULL){
        return;
    }
    printf("%d",root->data);
    pre_order(root->left);
    pre_order(root->right);
}
void post_order(struct Node* root) {
    if(root == NULL) return;
    post_order(root->left);
    post_order(root->right);
    printf("%d ", root->data);
}
int main(){
    struct Node* root = create_node(1);
    root->left = create_node(2);
    root->right = create_node(3);
    root->left->left = create_node(4);
    root->left->right = create_node(5);
    printf("ROOT NODE: %d\n",root->data);
    printf("LEFT CHILD OF ROOT: %d\n",root->left->data);
    printf("RIGHT CHILD OF ROOT: %d\n",root->right->data);
    printf("PREORDER = ");
    pre_order(root); 
    printf("\n");
    printf("POSTORDER = ");
    post_order(root); 
    printf("\n");
    printf("INORDER = ");
    in_order(root);
    printf("\n");
}
