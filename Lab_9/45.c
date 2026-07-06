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
    }
    save = first1;
    while (save->link != NULL)
    {
        save = save->link;
    }
    save->link = newnode;
}

void copy()
{
    struct node *save;
    while (save != NULL)
    {
        insertlast(save->info);
        save = save->link;
    }
    
}
void display()
{
    struct node *temp;

    if (first1 == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    temp = first1;
    printf("Node is: ");
    while (temp != NULL)
    {
        printf("%d ", temp->info);
        temp = temp->link;
    }
}
int main()
{
    insertlast(20);
    insertlast(2);
    insertlast(50);
    display1();

    return 0;
}