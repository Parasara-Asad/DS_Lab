#include <stdio.h>
#include <stdlib.h>

enum Color {RED, BLACK};

struct Node {
    int data;
    int color;
    struct Node *left, *right, *parent;
};

struct Node* root = NULL;

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = newNode->parent = NULL;
    newNode->color = RED;
    return newNode;
}

void rotateLeft(struct Node* pt) {
    struct Node* pt_right = pt->right;
    pt->right = pt_right->left;
    if (pt->right != NULL)
        pt->right->parent = pt;
    pt_right->parent = pt->parent;
    if (pt->parent == NULL)
        root = pt_right;
    else if (pt == pt->parent->left)
        pt->parent->left = pt_right;
    else
        pt->parent->right = pt_right;
    pt_right->left = pt;
    pt->parent = pt_right;
}

void rotateRight(struct Node* pt) {
    struct Node* pt_left = pt->left;
    pt->left = pt_left->right;
    if (pt->left != NULL)
        pt->left->parent = pt;
    pt_left->parent = pt->parent;
    if (pt->parent == NULL)
        root = pt_left;
    else if (pt == pt->parent->left)
        pt->parent->left = pt_left;
    else
        pt->parent->right = pt_left;
    pt_left->right = pt;
    pt->parent = pt_left;
}

void fixViolation(struct Node* pt) {
    struct Node* parent_pt = NULL;
    struct Node* grand_parent_pt = NULL;

    while ((pt != root) && (pt->color != BLACK) && (pt->parent->color == RED)) {
        parent_pt = pt->parent;
        grand_parent_pt = pt->parent->parent;

        if (parent_pt == grand_parent_pt->left) {
            struct Node* uncle_pt = grand_parent_pt->right;
            if (uncle_pt != NULL && uncle_pt->color == RED) {
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            } else {
                if (pt == parent_pt->right) {
                    rotateLeft(parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }
                rotateRight(grand_parent_pt);
                int t = parent_pt->color;
                parent_pt->color = grand_parent_pt->color;
                grand_parent_pt->color = t;
                pt = parent_pt;
            }
        } else {
            struct Node* uncle_pt = grand_parent_pt->left;
            if ((uncle_pt != NULL) && (uncle_pt->color == RED)) {
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            } else {
                if (pt == parent_pt->left) {
                    rotateRight(parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }
                rotateLeft(grand_parent_pt);
                int t = parent_pt->color;
                parent_pt->color = grand_parent_pt->color;
                grand_parent_pt->color = t;
                pt = parent_pt;
            }
        }
    }
    root->color = BLACK;
}

void insert(int data) {
    struct Node* pt = createNode(data);
    if (root == NULL) {
        pt->color = BLACK;
        root = pt;
        return;
    }
    struct Node* temp = root;
    struct Node* parent = NULL;
    while (temp != NULL) {
        parent = temp;
        if (pt->data < temp->data)
            temp = temp->left;
        else if (pt->data > temp->data)
            temp = temp->right;
        else
            return;
    }
    pt->parent = parent;
    if (pt->data < parent->data)
        parent->left = pt;
    else
        parent->right = pt;
    fixViolation(pt);
}

void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d(%c) ", root->data, root->color == RED ? 'R' : 'B');
    inorder(root->right);
}

int main() {
    insert(10);
    insert(20);
    insert(30);
    insert(15);
    
    printf("Inorder Traversal of Created Red-Black Tree:\n");
    inorder(root);
    printf("\n");
    return 0;
}
