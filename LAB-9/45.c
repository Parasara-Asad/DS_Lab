#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

struct node *first1 = NULL;
struct node *first2 = NULL;

void insertlast(int x)
{
    struct node *newnode, *save;

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = x;
    newnode->link = NULL;

    if (first1 == NULL)
    {
        first1 = newnode;
        return;
    }

    save = first1;

    while (save->link != NULL)
    {
        save = save->link;
    }

    save->link = newnode;
}

void insertlast2(int x)
{
    struct node *newnode, *save;

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = x;
    newnode->link = NULL;

    if (first2 == NULL)
    {
        first2 = newnode;
        return;
    }

    save = first2;

    while (save->link != NULL)
    {
        save = save->link;
    }

    save->link = newnode;
}

void copy()
{
    struct node *save;

    save = first1;

    while (save != NULL)
    {
        insertlast2(save->info);
        save = save->link;
    }
}

void display1()
{
    struct node *temp;

    if (first1 == NULL)
    {
        printf("First List is empty!\n");
        return;
    }

    temp = first1;

    printf("First List: ");

    while (temp != NULL)
    {
        printf("%d ", temp->info);
        temp = temp->link;
    }

    printf("\n");
}

void display2()
{
    struct node *temp;

    if (first2 == NULL)
    {
        printf("Copy List is empty!\n");
        return;
    }

    temp = first2;

    printf("Copy List: ");

    while (temp != NULL)
    {
        printf("%d ", temp->info);
        temp = temp->link;
    }

    printf("\n");
}

int main()
{
    int size, x;

    printf("Enter size of list: ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++)
    {
        printf("Enter node info: ");
        scanf("%d", &x);
        insertlast(x);
    }

    printf("\n");
    display1();

    copy();

    display2();

    return 0;
}