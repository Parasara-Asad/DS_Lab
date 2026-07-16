#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};
struct node *first = NULL;

void sort()
{
    struct node *save1,*save2;
    for (save1 = first; save1 != NULL; save1 = save1->link)
    {
        for (save2 = first; save2->link != NULL; save2 = save2->link)
        {
            if (save2->info > save2->link->info)
            {
                int temp = save2->info;
                save2->info = save2->link->info;
                save2->link->info = temp;
            }
            
        }
    }
}

void insertfirst(int x)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = x;
    newnode->link = first;
    first = newnode;
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
    printf("After Sort link list is: ");
    sort();
    display();

    return 0;
}