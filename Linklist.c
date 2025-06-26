#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node *next;
} Node;

Node *create_node(int item, Node *next) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Error: could not create a new node\n");
        exit(1);
    }
    new_node->data = item;
    new_node->next = next;
    return new_node;
}

Node *remove_node(Node *head, Node *node) {
    if (node == head) {
        head = node->next;
        free(node);
        return head;
    }
    Node *current_node = head;
    while (current_node != NULL) {
        if (current_node->next == node) {
            break;
        }
        current_node = current_node->next;
    }
    if (current_node == NULL) {
        return head;
    }
    current_node->next = node->next;
    free(node);
    return head;
}

void print_list(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

Node *prepend(Node *head, int item) {
    Node *new_node = create_node(item, head);
    return new_node;
}

Node *append(Node *head, int item) {
    Node *new_node = create_node(item, NULL);
    if (head == NULL) {
        return new_node;
    }
    Node *current_node = head;
    while (current_node->next != NULL) {
        current_node = current_node->next;
    }
    current_node->next = new_node;
    return head;
}

void insert(Node *node, int item) {
    Node *new_node = create_node(item, node->next);
    node->next = new_node;
}

int main() {
    Node *n, *n1,*n4, *n2, *n3, *head;
     // Create nodes
    n = create_node(10, NULL);
    n1 = create_node(24, NULL);
    n2 = create_node(44, NULL);
    n3 = create_node(55, NULL);
    n4 = create_node(99,NULL);

    // Link the nodes to form the list: 10 -> 24 -> 44 -> 55
    n->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    // Demonstrate prepend
    head = prepend(head, 30); // List: 30
    head = prepend(head, 20); // List: 20 -> 30
    head = prepend(head, 10); // List: 10 -> 20 -> 30

    printf("After prepending 10, 20, 30:\n");
    print_list(head);

    // Demonstrate append
    head = append(head, 40);  // List: 10 -> 20 -> 30 -> 40
    head = append(head, 50);  // List: 10 -> 20 -> 30 -> 40 -> 50

    printf("After appending 40 and 50:\n");
    print_list(head);

    // Demonstrate insert after 30
    Node *current = head;
    while (current != NULL && current->data != 30) {
        current = current->next;
    }
    if (current != NULL) {
        insert(current, 35);  // Insert after 30
    }

    printf("After inserting 35 after 30:\n");
    print_list(head);

    // Cleanup: remove all nodes
    while (head != NULL) {
        head = remove_node(head, head);
    }

    return 0;
}



