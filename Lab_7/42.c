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
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = x;
    newnode->link = first;
    first = newnode;
}

void insertlast(int x)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = x;
    newnode->link = NULL;
    if (newnode == NULL)
    {
        return;
    }

    if (first == NULL)
    {
        first = newnode;
    }
    else
    {
        struct node *save = first;
        while (save->link != NULL)
        {
            save = save->link;
        }
        save->link = newnode;
    }
}

void deletefirst()
{
    struct node *temp = first;
    if (first == NULL)
    {
        printf("List is empty!");
        return;
    }
    else
    {
        first = first->link;
        free(temp);
    }
}

void deletelast()
{
    if (first == NULL)
    {
        printf("List is empty");
        return;
    }
    if (first->link == NULL)
    {
        free(first);
        first->link = NULL;
    }
    else
    {
        struct node *save = first, *temp = first;
        while (save->link->link != NULL)
        {
            save = save->link;
        }
        temp = save->link;
        free(temp);
        save->link = NULL;
    }
}

void delete_spe_pos(int x)
{
    if (first == NULL)
    {
        printf("List is empty!");
        return;
    }
    if (first->info == x)
    {
        struct node *temp = first;
        first = first->link;
        free(temp);
    }
    struct node *save = first;
    struct node *pred = save;
    while (save != NULL && save->info != x)
    {
        pred = save;
        save = save->link;
    }
    if (save == NULL)
    {
        printf("Element not found");
        return;
    }
    pred->link = save->link;
    free(save);
}

void conut_nodes(){
    int count=0;
    struct node *save=first;
    while (save!=NULL)
    {
        count++;
        save = save->link;
    }
    printf("Number of nodes is: %d\n",count);
    
}

void display()
{
    if (first == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct node *save = first;
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
    insertfirst(3);
    insertfirst(2);
    insertfirst(1);
    insertlast(4);
    insertlast(5);
    insertlast(6);
    deletefirst();
    deletelast();
    delete_spe_pos(4);
    conut_nodes();
    display();
    return 0;
}