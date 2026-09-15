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

struct Node* constructTreeUtil(int pre[], int post[], int* preIndex, int l, int h, int size) {
    if (*preIndex >= size || l > h)
        return NULL;

    struct Node* root = createNode(pre[*preIndex]);
    ++(*preIndex);

    if (l == h)
        return root;

    int i;
    for (i = l; i <= h; ++i) {
        if (pre[*preIndex] == post[i])
            break;
    }

    if (i <= h) {
        root->left = constructTreeUtil(pre, post, preIndex, l, i, size);
        root->right = constructTreeUtil(pre, post, preIndex, i + 1, h - 1, size);
    }
    return root;
}

struct Node* constructTree(int pre[], int post[], int size) {
    int preIndex = 0;
    return constructTreeUtil(pre, post, &preIndex, 0, size - 1, size);
}

void inorder(struct Node* node) {
    if (node == NULL)
        return;
    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
}

int main() {
    int pre[] = { 1, 2, 4, 8, 9, 5, 3, 6, 7 };
    int post[] = { 8, 9, 4, 5, 2, 6, 7, 3, 1 };
    int size = sizeof(pre) / sizeof(pre[0]);

    struct Node* root = constructTree(pre, post, size);
    printf("Inorder traversal of the constructed tree: \n");
    inorder(root);
    printf("\n");
    return 0;
}
