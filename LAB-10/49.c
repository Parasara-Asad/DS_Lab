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

int findGCD(int x, int y)
{
    int small = (x < y) ? x : y;

    for (int i = small; i >= 1; i--)
    {
        if (x % i == 0 && y % i == 0)
        {
            return i;
        }
    }

    return 1;
}

void insertbetweenGCD()
{
    struct node *save, *newnode;

    save = first;

    while (save != NULL && save->link != NULL)
    {
        newnode = (struct node *)malloc(sizeof(struct node));

        newnode->info = findGCD(save->info, save->link->info);

        newnode->link = save->link;

        save->link = newnode;

        save = newnode->link;
    }
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
    printf("\n");
}

int main()
{
    insertfirst(1);
    insertfirst(4);
    insertfirst(5);
    insertfirst(2);
    insertfirst(1);
    printf("Before link list is: ");
    display();
    printf("Between GCD link list: ");
    insertbetweenGCD();
    display();
    return 0;
}