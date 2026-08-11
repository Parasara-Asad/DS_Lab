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

void removeduplicates()
{
    struct node *save;
    if (first == NULL)
    {
        return;
    }
    else
    {
        save = first;
        while (save->link != NULL)
        {
            if (save->info == save->link->info)
            {
               struct node *temp = save->link;
                save->link = save->link->link;
                free(temp);
            }
            else{
                save = save->link;
            }
        }
    }
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
    insertfirst(27);
    insertfirst(27);
    insertfirst(13);
    insertfirst(13);
    insertfirst(13);
    insertfirst(6);
    insertfirst(1);
    insertfirst(1);
    display();
    removeduplicates();
    display();
    return 0;
}