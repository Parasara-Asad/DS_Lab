#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int info;
    struct Node *next;
};

struct Node *First;
void splitCircularlist(struct Node *head)
{
    struct Node *ptr = head;
    struct Node *prev;
    struct Node *save = head;
    int c = 0;
    while (ptr->next != head)
    {
        c++;
        ptr = ptr->next;
    }
    c++;
    prev = save;
    int i = 0;
    while (i != c / 2)
    {
        prev = save;
        save = save->next;
        i++;
    }

    struct Node *newHead;
    newHead = save->next;
    struct Node *adress = ptr->next;
    ptr->next = save->next;
    save->next = adress;
    struct Node *ptr1 = head;
    struct Node *ptr2 = newHead;
    printf("first circular list after split\n");
    while (ptr1->next != head)
    {
        printf("Element : %d\n", ptr1->info);
        ptr1 = ptr1->next;
    }
    printf("Element : %d\n", ptr1->info);
    printf("second circular list after split\n");

    while (ptr2->next != newHead)
    {
        printf("Element : %d\n", ptr2->info);
        ptr2 = ptr2->next;
    }
    printf("Element : %d\n", ptr2->info);
}
// main method here start
void main()
{

    struct Node *n1 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *n2 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *n3 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *n4 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *n5 = (struct Node *)malloc(sizeof(struct Node));
    First = n1;
    n1->info = 12;
    n2->info = 23;
    n3->info = 34;
    n4->info = 54;
    n5->info = 67;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n1;

    
    splitCircularlist(First);
}