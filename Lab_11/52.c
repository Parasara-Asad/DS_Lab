
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

struct node *first = NULL;
struct node *head1 = NULL;
struct node *head2 = NULL;

void insertfirst(int x)
{
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));

    newnode->info = x;

    if (first == NULL)
    {
        newnode->link = newnode;
        first = newnode;
    }
    else
    {
        struct node *save = first;

        while (save->link != first)
        {
            save = save->link;
        }

        newnode->link = first;
        save->link = newnode;
        first = newnode;
    }
}

void split()
{
    struct node *slow = first;
    struct node *fast = first;

    while (fast->link != first && fast->link->link != first)
    {
        slow = slow->link;
        fast = fast->link->link;
    }

    head1 = first;
    head2 = slow->link;

    // Make first half circular
    slow->link = head1;

    // Find last node of second half
    fast = head2;

    while (fast->link != first)
    {
        fast = fast->link;
    }

    // Make second half circular
    fast->link = head2;
}

void display()
{
    if (first == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct node *save = first;

    printf("Original List: ");

    do
    {
        printf("%d ", save->info);
        save = save->link;
    } while (save != first);

    printf("\n");
}

void display1()
{
    struct node *save = head1;

    printf("First Half: ");

    do
    {
        printf("%d ", save->info);
        save = save->link;
    } while (save != head1);

    printf("\n");
}

void display2()
{
    struct node *save = head2;

    printf("Second Half: ");

    do
    {
        printf("%d ", save->info);
        save = save->link;
    } while (save != head2);

    printf("\n");
}

int main()
{
    insertfirst(4);
    insertfirst(3);
    insertfirst(2);
    insertfirst(1);

    display();

    split();

    display1();
    display2();

    return 0;
}
