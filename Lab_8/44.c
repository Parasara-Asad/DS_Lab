#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

struct node *first1 = NULL;

void insertfirst(int x)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = x;
    newnode->link = first1;
    first1 = newnode;
}

void removeduplicat()
{
    struct node *save, *temp;
    if (first1 == NULL)
    {
        printf("List is empty!");
        return;
    }
    save = first1;
    while (save->link != NULL)
    {
        if (save->info == save->link->info)
        {
            temp = save->link;
            save->link = temp->link;
            free(temp);
        }
        else
        {
            save = save->link;
        }
    }
}

void display()
{
    struct node *save;
    if (first1 == NULL)
    {
        printf("List is empty!");
        return;
    }
    save = first1;
    while (save != NULL)
    {
        printf(" %d ", save->info);
        save = save->link;
    }
    printf("\n");
}
int main()
{
    insertfirst(1);
    insertfirst(1);
    insertfirst(1);
    insertfirst(2);
    insertfirst(2);
    insertfirst(50);
    insertfirst(5);
    insertfirst(50);
    removeduplicat();
    display();
    return 0;
}