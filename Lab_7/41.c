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

void dispaly()
{
    struct node *save;
    save = first;
    if (first == NULL)
    {
        printf("List is empty");
    }
    printf("List is: ");
    while (save != NULL)
    {
        printf(" %d", save->info);
        save = save->link;
    }
}

int main()
{
    int n;
    printf("Enter how many data: ");
    scanf("%d",&n);
    int x;
    for (int i = 0; i < n; i++)
    {
        printf("Enter data: ");
        scanf("%d",&x);
        insertfirst(x);
    }

    dispaly();
    return 0;
}

// struct node *f1,*f2,*f3,*temp;
// f1 = (struct node *)malloc(sizeof(struct node));
// printf("Enter data: ");
// scanf("%d",&f1->info);
// f2 = (struct node *)malloc(sizeof(struct node));
// printf("Enter data: ");
// scanf("%d",&f2->info);
// f1->Link = f2->Link;
// f3 = (struct node *)malloc(sizeof(struct node));
// printf("Enter data: ");
// scanf("%d",&f3->info);
// f2->Link = NULL;
// if (f1 == NULL)
// {
//     printf("List is empty!");
// }
//     printf("[%d %d %d]",f1->info,f2->info,f3->info);