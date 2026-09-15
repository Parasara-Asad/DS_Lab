#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int isMirror(struct Node* node1, struct Node* node2) {
    if (node1 == NULL && node2 == NULL) return 1;
    if (node1 == NULL || node2 == NULL) return 0;
    return (node1->data == node2->data)
        && isMirror(node1->left, node2->right)
        && isMirror(node1->right, node2->left);
}

int isSymmetric(struct Node* root) {
    return isMirror(root, root);
}

int main() {
    struct Node* root = createNode(8);
    root->left = createNode(5);
    root->right = createNode(5);
    root->left->left = createNode(3);
    root->left->right = createNode(6);
    root->right->left = createNode(6);
    root->right->right = createNode(3);

    if (isSymmetric(root)) {
        printf("Given tree is symmetric\n");
    } else {
        printf("Given tree is not symmetric\n");
    }

    return 0;
}
