#include <stdio.h>
#include <stdlib.h>
struct Node {
    int keys[2];
    struct Node *child[3];
    int num_keys;
    int is_leaf;
};

struct Node* createNode() {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->num_keys = 0;
    newNode->is_leaf = 1;
    newNode->child[0] = newNode->child[1] = newNode->child[2] = NULL;
    return newNode;
}

void printTree(struct Node* root) {
    if (root != NULL) {
        int i;
        for (i = 0; i < root->num_keys; i++) {
            printTree(root->child[i]);
            printf("%d ", root->keys[i]);
        }
        printTree(root->child[i]);
    }
}

int main() {
    struct Node* root = createNode();
    root->keys[0] = 10;
    root->num_keys = 1;
    
    root->child[0] = createNode();
    root->child[0]->keys[0] = 5;
    root->child[0]->num_keys = 1;
    
    root->child[1] = createNode();
    root->child[1]->keys[0] = 20;
    root->child[1]->keys[1] = 30;
    root->child[1]->num_keys = 2;
    
    root->is_leaf = 0;

    printf("2-3 Tree elements: ");
    printTree(root);
    printf("\n");
    return 0;
}
