#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int item) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    temp->info = item;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct Node* insert(struct Node* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }
    if (key < root->info) {
        root->left = insert(root->left, key);
    } else if (key > root->info) {
        root->right = insert(root->right, key);
    } else {
        printf("Duplicate element not allowed.\n");
    }
    return root;
}

struct Node* getMinValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) {
        return root;
    }
    if (key < root->info) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->info) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node to be deleted found
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        // Node with two children
        struct Node* temp = getMinValueNode(root->right);
        root->info = temp->info;
        root->right = deleteNode(root->right, temp->info);
    }
    return root;
}

struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->info == key) {
        return root;
    }
    if (key < root->info) {
        return search(root->left, key);
    }
    return search(root->right, key);
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->info);
        inorder(root->right);
    }
}

void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->info);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->info);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, item;
    struct Node* result = NULL;

    while (1) {
        printf("\n--- Binary Search Tree Menu ---\n");
        printf("1. Insert a node\n");
        printf("2. Delete a node\n");
        printf("3. Search a node\n");
        printf("4. Preorder Traversal\n");
        printf("5. Postorder Traversal\n");
        printf("6. Inorder Traversal\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item to insert: ");
                scanf("%d", &item);
                root = insert(root, item);
                break;
            case 2:
                printf("Enter item to delete: ");
                scanf("%d", &item);
                root = deleteNode(root, item);
                break;
            case 3:
                printf("Enter item to search: ");
                scanf("%d", &item);
                result = search(root, item);
                if (result != NULL) {
                    printf("Element %d found in the BST.\n", item);
                } else {
                    printf("Element %d not found in the BST.\n", item);
                }
                break;
            case 4:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 5:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 6:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 7:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}