#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};
struct node *first1 = NULL;
struct node *first2 = NULL;

void insertlast1(int x)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = x;
    newnode->link = NULL;
    if (newnode == NULL)
    {
        return;
    }

    if (first1 == NULL)
    {
        first1 = newnode;
    }
    else
    {
        struct node *save = first1;
        while (save->link != NULL)
        {
            save = save->link;
        }
        save->link = newnode;
    }
}
void insertlast2(int x)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = x;
    newnode->link = NULL;
    if (newnode == NULL)
    {
        return;
    }

    if (first2 == NULL)
    {
        first2 = newnode;
    }
    else
    {
        struct node *save = first2;
        while (save->link != NULL)
        {
            save = save->link;
        }
        save->link = newnode;
    }
}

void copylist()
{
    struct node *save = first1;
    if (first1 == NULL)
    {
        return;
    }
    while (save != NULL)
    {
        insertlast2(save->info);
        save = save->link;
    }
}

void display1()
{
    if (first1 == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct node *save = first1;
    printf("List is:");
    while (save != NULL)
    {
        printf(" %d", save->info);
        save = save->link;
    }
    printf("\n");
}
void display2()
{
    if (first2 == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct node *save = first2;
    printf("List is:");
    while (save != NULL)
    {
        printf(" %d", save->info);
        save = save->link;
    }
    printf("\n");
}

int main()
{
    insertlast1(1);
    insertlast1(2);
    insertlast1(3);
    insertlast1(4);
    display1();
    copylist();
    display2();

    return 0;
}