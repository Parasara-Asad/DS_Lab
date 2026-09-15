#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int pow;
    struct Node* next;
};

struct Node* createNode(int coeff, int pow) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = NULL;
    return newNode;
}

void insertNode(struct Node** head, int coeff, int pow) {
    struct Node* newNode = createNode(coeff, pow);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

struct Node* addPolynomials(struct Node* p1, struct Node* p2) {
    struct Node* res = NULL;
    while (p1 != NULL && p2 != NULL) {
        if (p1->pow > p2->pow) {
            insertNode(&res, p1->coeff, p1->pow);
            p1 = p1->next;
        } else if (p1->pow < p2->pow) {
            insertNode(&res, p2->coeff, p2->pow);
            p2 = p2->next;
        } else {
            insertNode(&res, p1->coeff + p2->coeff, p1->pow);
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    while (p1 != NULL) {
        insertNode(&res, p1->coeff, p1->pow);
        p1 = p1->next;
    }
    while (p2 != NULL) {
        insertNode(&res, p2->coeff, p2->pow);
        p2 = p2->next;
    }
    return res;
}

void printPolynomial(struct Node* head) {
    while (head != NULL) {
        printf("%dx^%d", head->coeff, head->pow);
        head = head->next;
        if (head != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

int main() {
    struct Node* p1 = NULL;
    insertNode(&p1, 5, 2);
    insertNode(&p1, 4, 1);
    insertNode(&p1, 2, 0);

    struct Node* p2 = NULL;
    insertNode(&p2, 5, 1);
    insertNode(&p2, 5, 0);

    printPolynomial(p1);
    printPolynomial(p2);

    struct Node* res = addPolynomials(p1, p2);
    printPolynomial(res);

    return 0;
}
