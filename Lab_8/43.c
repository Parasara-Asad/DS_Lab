#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};
struct node *first = NULL;
struct node *first1 = NULL;
struct node *first2 = NULL;

void insertfirst1(int x)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = x;
    newnode->link = first1;
    first1 = newnode;
}
void insertfirst2(int x)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = x;
    newnode->link = first2;
    first2 = newnode;
}

void sameornot()
{
    int flag = 0;
    struct node *save1 = first1;
    struct node *save2 = first2;
    while (save1 != NULL && save2 != NULL)
    {
        if (save1->info != save2->info)
        {
            printf("List is not same\n");
            return;
        }

        save1 = save1->link;
        save2 = save2->link;
    }
    if (save1 == NULL && save2 == NULL)
    {
        printf("Lists are Same\n");
    }
    else
    {
        printf("Lists are NOT same \n");
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
    insertfirst1(1);
    insertfirst1(2);
    insertfirst1(3);
    insertfirst2(1);
    insertfirst2(2);
    insertfirst2(3);
    sameornot();
    display1();
    display2();

    return 0;
}