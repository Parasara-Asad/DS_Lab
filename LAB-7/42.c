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

int firstdelete()
{
    struct node *save;

    if (first == NULL)
    {
        printf("List is empty!\n");
        return 0;
    }

    save = first;
    first = first->link;
    free(save);

    return 1;
}

void insertlast(int x)
{
    struct node *newnode, *save;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = x;
    newnode->link = NULL;
    if (first == NULL)
    {
        first = newnode;
    }
    save = first;
    while (save->link != NULL)
    {
        save = save->link;
    }
    save->link = newnode;
}

int lastdelete()
{
    struct node *save, *pred;
    if (first == NULL)
    {
        printf("List is empty!");
        return 0;
    }
    save = first;
    while (save->link != NULL)
    {
        pred = save;
        save = save->link;
    }
    pred->link = NULL;
    free(save);
    return 1;
}

int spe_pos_delete(int x)
{
    struct node *save, *pred;

    if (first == NULL)
    {
        printf("List is empty!\n");
        return 0;
    }

    pred = NULL;
    save = first;

    while (save != NULL && save->info != x)
    {
        pred = save;
        save = save->link;
    }

    if (save == NULL)
    {
        printf("Value not found!\n");
        return 0;
    }

    if (pred == NULL)
    {
        first = save->link;
    }
    else
    {
        pred->link = save->link;
    }

    free(save);
    return 1;
}

int count_nodes(){
    int count = 0;
    struct node *save;
    if (save == NULL)
    {
        printf("List is empty!");
    }
    save = first;
    while (save != NULL)
    {
        save = save->link;
        count++;
    }
    return count;
}

void display()
{
    struct node *temp;

    if (first == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    temp = first;
    printf("\n=============================================\n");
    printf("Node is: ");
    while (temp != NULL)
    {
        printf("%d ", temp->info);
        temp = temp->link;
    }
    printf("\n=============================================\n");
}

int main()
{
    int n;
    while (1)
    {
        printf("(1) - Insert at first\n");
        printf("(2) - display all nodes\n");
        printf("(3) - Delete at first\n");
        printf("(4) - Insert at last\n");
        printf("(5) - Delete at last\n");
        printf("(6) - Delete at specified position\n");
        printf("(7) - Count nodes\n");
        printf("(8) - Exit\n");
        printf("Enter what did you want: ");
        scanf("%d", &n);
        if (n == 1)
        {
            insertfirst(20);
            insertfirst(10);
            insertfirst(8);
            insertfirst(4);
        }
        else if (n == 2)
        {
            display();
        }
        else if (n == 3)
        {
            firstdelete();
        }
        else if (n == 4)
        {
            insertlast(50);
        }
        else if (n == 5)
        {
            lastdelete();
        }
        else if (n == 6)
        {
            spe_pos_delete(10);
        }
        else if (n == 7)
        {
            printf("Count of node is: %d/n", count_nodes());
        }

        else if (n == 8)
        {
            break;
        }
    }

    return 0;
}