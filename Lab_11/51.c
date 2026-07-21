#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};
struct node *first = NULL;
struct node *last = NULL;

void insertfirst(int x)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = x;

    if (first == NULL)
    {
        first = last = newnode;
        newnode->link = first;
        return;
    }
    newnode->link = first;
    first = newnode;
    last->link = first;
}

void insertlast(int x)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = x;
    if (first == NULL)
    {
        first = last = newnode;
        newnode->link = first;
        return;
    }
    last->link = newnode;
    newnode->link = first;
    last = newnode;
}

void deleteposition(int pos)
{
    if (first == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    struct node *save = first;
    struct node *pred = NULL;
    int count = 1;

    if (pos == 1)
    {
        if (first == last) 
        {
            free(first);
            first = last = NULL;
            return;
        }

        first = first->link;
        last->link = first;
        free(save);
        return;
    }

    while (count < pos && save != last)
    {
        pred = save;
        save = save->link;
        count++;
    }

    if (count != pos)
    {
        printf("Invalid Position!\n");
        return;
    }

    pred->link = save->link;

    if (save == last)
    {
        last = pred;
    }

    free(save);
}

void display()
{
    if (first == NULL)
    {
        printf("List is empty!");
        return;
    }

    struct node *save = first;
    printf("\n=====================\n");
    while (save->link != first)
    {
        printf("%d ", save->info);
        save = save->link;
    }

    printf("%d\n", save->info);
    printf("=====================\n");
}

int main()
{
    int n;
    while (1)
    {
        printf("(1)-Insert a node at the front of the linked list\n");
        printf("(2)-Delete a node from specified position\n");
        printf("(3)-Insert a node at the end of the linked list\n");
        printf("(4)-Display all nodes\n");
        printf("(5)-Exit\n");
        printf("Enter what did you want: ");
        scanf("%d", &n);
        if (n == 1)
        {
            insertfirst(5);
            insertfirst(4);
            insertfirst(3);
            insertfirst(1);
        }
        else if (n == 2)
        {
            deleteposition(2);
        }
        else if (n == 3)
        {
            insertlast(10);
        }
        else if (n == 4)
        {
            display();
        }
        else if (n == 5)
        {
            break;
        }
        else
        {
            printf("Invalid input");
        }
    }

    return 0;
}