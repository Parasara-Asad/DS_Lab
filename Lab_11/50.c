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

void insertlast(int x){
    
}
void display()
{
    if (first == NULL)
    {
        printf("List is empty!");
        return;
    }

    struct node *save = first;

    while (save->link != first)
    {
        printf("%d ", save->info);
        save = save->link;
    }

    printf("%d\n", save->info); 
}

int main()
{
    insertfirst(1);
    insertfirst(4);
    insertfirst(5);
    insertfirst(2);
    insertfirst(1);
    printf("link list is: ");
    display();

    return 0;
}