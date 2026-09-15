#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contact {
    char name[100];
    char phone[20];
    struct Contact* left;
    struct Contact* right;
};

struct Contact* createContact(char* name, char* phone) {
    struct Contact* newContact = (struct Contact*)malloc(sizeof(struct Contact));
    strcpy(newContact->name, name);
    strcpy(newContact->phone, phone);
    newContact->left = NULL;
    newContact->right = NULL;
    return newContact;
}

struct Contact* addEntry(struct Contact* root, char* name, char* phone) {
    if (root == NULL) return createContact(name, phone);
    if (strcmp(name, root->name) < 0) {
        root->left = addEntry(root->left, name, phone);
    } else if (strcmp(name, root->name) > 0) {
        root->right = addEntry(root->right, name, phone);
    }
    return root;
}

struct Contact* minValueContact(struct Contact* node) {
    struct Contact* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

struct Contact* removeEntry(struct Contact* root, char* name) {
    if (root == NULL) return root;
    if (strcmp(name, root->name) < 0) {
        root->left = removeEntry(root->left, name);
    } else if (strcmp(name, root->name) > 0) {
        root->right = removeEntry(root->right, name);
    } else {
        if (root->left == NULL) {
            struct Contact* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Contact* temp = root->left;
            free(root);
            return temp;
        }
        struct Contact* temp = minValueContact(root->right);
        strcpy(root->name, temp->name);
        strcpy(root->phone, temp->phone);
        root->right = removeEntry(root->right, temp->name);
    }
    return root;
}

void searchEntry(struct Contact* root, char* name) {
    if (root == NULL) {
        printf("Contact not found.\n");
        return;
    }
    if (strcmp(name, root->name) == 0) {
        printf("Found: %s - %s\n", root->name, root->phone);
    } else if (strcmp(name, root->name) < 0) {
        searchEntry(root->left, name);
    } else {
        searchEntry(root->right, name);
    }
}

void listAscending(struct Contact* root) {
    if (root != NULL) {
        listAscending(root->left);
        printf("%s: %s\n", root->name, root->phone);
        listAscending(root->right);
    }
}

void listDescending(struct Contact* root) {
    if (root != NULL) {
        listDescending(root->right);
        printf("%s: %s\n", root->name, root->phone);
        listDescending(root->left);
    }
}

int main() {
    struct Contact* root = NULL;
    root = addEntry(root, "Alice", "12345");
    root = addEntry(root, "Bob", "67890");
    root = addEntry(root, "Charlie", "11223");
    
    printf("Ascending Order:\n");
    listAscending(root);
    printf("\nDescending Order:\n");
    listDescending(root);
    
    printf("\nSearching for Bob:\n");
    searchEntry(root, "Bob");
    
    root = removeEntry(root, "Alice");
    printf("\nAfter removing Alice (Ascending Order):\n");
    listAscending(root);
    
    return 0;
}
