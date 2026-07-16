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

void swapK(int k)
{
    struct node *p1, *p2;
    int n = 0, i, temp;

    p1 = first;
    while (p1 != NULL)
    {
        n++;
        p1 = p1->link;
    }

    if (k > n || k <= 0)
    {
        printf("Invalid K");
        return;
    }

    p1 = first;
    for (i = 1; i < k; i++)
    {
        p1 = p1->link;
    }

    p2 = first;
    for (i = 1; i < (n - k + 1); i++)
    {
        p2 = p2->link;
    }

    temp = p1->info;
    p1->info = p2->info;
    p2->info = temp;
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
    swapK(2);
    printf("After sawp link list is: ");
    display();

    return 0;
}