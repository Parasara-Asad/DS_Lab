#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *lptr;
    struct node *rptr;
};

struct node *first = NULL;

void insertfirst(int x)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    newnode->info = x;
    newnode->lptr = NULL;
    newnode->rptr = first;

    if (first != NULL)
    {
        first->lptr = newnode;
    }

    first = newnode;

    printf("Node Inserted at Front.\n");
}

void insertlast(int x)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    struct node *save;

    newnode->info = x;
    newnode->rptr = NULL;

    if (first == NULL)
    {
        newnode->lptr = NULL;
        first = newnode;
        printf("Node Inserted.\n");
        return;
    }

    save = first;

    while (save->rptr != NULL)
    {
        save = save->rptr;
    }

    save->rptr = newnode;
    newnode->lptr = save;

    printf("Node Inserted at End.\n");
}

void deleteposition(int pos)
{
    struct node *save = first;
    int i;

    if (first == NULL)
    {
        printf("List is Empty.\n");
        return;
    }

    if (pos == 1)
    {
        first = first->rptr;

        if (first != NULL)
            first->lptr = NULL;

        free(save);
        return;
    }

    for (i = 1; i < pos && save != NULL; i++)
    {
        save = save->rptr;
    }

    if (save == NULL)
    {
        printf("Invalid Position.\n");
        return;
    }

    if (save->rptr == NULL)
    {
        save->lptr->rptr = NULL;
        free(save);
        printf("Node Deleted.\n");
        return;
    }

    save->lptr->rptr = save->rptr;
    save->rptr->lptr = save->lptr;

    free(save);

    printf("Node Deleted.\n");
}

void display()
{
    struct node *save = first;

    if (first == NULL)
    {
        printf("List is Empty.\n");
        return;
    }

    printf("\nList : ");

    while (save != NULL)
    {
        printf("%d ", save->info);
        save = save->rptr;
    }

    printf("\n");
}

// Main Function
int main()
{
    int choice, x, pos;

    while (1)
    {
        printf("1. Insert at Front\n");
        printf("2. Delete from Specified Position\n");
        printf("3. Insert at End\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter Choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter Value : ");
            scanf("%d", &x);
            insertfirst(x);
            break;

        case 2:
            printf("Enter Position : ");
            scanf("%d", &pos);
            deleteposition(pos);
            break;

        case 3:
            printf("Enter Value : ");
            scanf("%d", &x);
            insertlast(x);
            break;

        case 4:
            display();
            break;

        case 5:
            printf("Program Terminated.\n");
            exit(0);

        default:
            printf("Invalid Choice.\n");
        }
    }

    return 0;
}