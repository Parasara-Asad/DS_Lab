#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};
struct node *first = NULL;

void insertfirst(int x)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = x;
    newnode->link = first;
    first = newnode;
}

void reverse()
{
    struct node *curr = first;
    struct node *prev = NULL;
    struct node *next = NULL;
    while (curr != NULL)
    {
        next = curr->link;
        curr->link = prev;
        prev = curr;
        curr = next;
    }
    first = prev;
}

void display()
{
    if (first == NULL)
    {
        printf("List is empty!");
        return;
    }
    struct node *save = first;
    while (save != NULL)
    {
        printf("%d ", save->info);
        save = save->link;
    }
}

int main()
{
    insertfirst(5);
    insertfirst(4);
    insertfirst(3);
    insertfirst(2);
    insertfirst(1);
    display();
    reverse();
    printf("\n");
    display();
    return 0;
}