#include<stdio.h>
#include<stdlib.h>
typedef struct node Node;
   struct node {
    int data;
    Node *left;
    Node *right;
};
Node *create_node(int item){
    Node *new_node = (Node *) malloc(sizeof(Node));
    if (new_node == NULL){
        printf("could not create a Node");
        exit(1);
    }
    new_node->data = item;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}
void add_left_child(Node *node,Node *child){
    node->left = child;
}
void add_right_child(Node *node, Node *child){
    node->right = child;
}

void post_order(Node *node){
    if(node->left !=NULL){
        post_order(node->left);
    }
    if(node->right != NULL){
        post_order(node->right);
    }
    printf("%d",node->data);
}

Node *Ptree(){
    Node *three = create_node(4);
    Node *five = create_node(5);
    Node *eight = create_node(8);
    Node *ten = create_node(10);
    post_order(three);
    post_order(ten);
    post_order(eight);
    return ten;
}


Node *create_tree(){
    Node *two = create_node(2);
    Node *seven = create_node(7);
    Node *nine = create_node(9);
    add_left_child(two,seven);
    add_right_child(two,nine);
    Node *one = create_node(1);
    Node *six = create_node(6);
    add_left_child(seven,one);
    add_right_child(seven,six);
    return six;
}
int main(){
    Node *root = create_tree();
    Node *post_order = Ptree();
    printf("%d\n",root->data);
    printf("%d\n",post_order->data);
    return 0;
}
