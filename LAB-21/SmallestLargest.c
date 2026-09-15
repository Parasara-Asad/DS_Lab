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

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) return createNode(data);
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

void findMinMax(struct Node* root) {
    if (root == NULL) {
        printf("Tree is empty.\n");
        return;
    }
    struct Node* temp = root;
    while (temp->left != NULL) {
        temp = temp->left;
    }
    printf("Smallest element: %d\n", temp->data);

    temp = root;
    while (temp->right != NULL) {
        temp = temp->right;
    }
    printf("Largest element: %d\n", temp->data);
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    
    findMinMax(root);
    return 0;
}
