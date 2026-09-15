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

int height(struct Node* node) {
    if (node == NULL) return 0;
    int lh = height(node->left);
    int rh = height(node->right);
    return (lh > rh ? lh : rh) + 1;
}

int isBalanced(struct Node* root) {
    if (root == NULL) return 1;
    int lh = height(root->left);
    int rh = height(root->right);
    int diff = lh > rh ? lh - rh : rh - lh;
    if (diff <= 1 && isBalanced(root->left) && isBalanced(root->right)) {
        return 1;
    }
    return 0;
}

int main() {
    struct Node* root = createNode(3);
    root->left = createNode(9);
    root->right = createNode(20);
    root->right->left = createNode(15);
    root->right->right = createNode(7);

    if (isBalanced(root)) {
        printf("TRUE\n");
    } else {
        printf("FALSE\n");
    }

    return 0;
}
