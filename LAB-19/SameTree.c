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

int isSameTree(struct Node* p, struct Node* q) {
    if (p == NULL && q == NULL) return 1;
    if (p == NULL || q == NULL) return 0;
    if (p->data != q->data) return 0;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main() {
    struct Node* root1 = createNode(3);
    root1->left = createNode(2);
    root1->right = createNode(4);
    root1->left->left = createNode(1);

    struct Node* root2 = createNode(3);
    root2->left = createNode(2);
    root2->right = createNode(4);
    root2->left->left = createNode(1);

    if (isSameTree(root1, root2)) {
        printf("Given trees are same\n");
    } else {
        printf("Given trees are not same\n");
    }

    return 0;
}
