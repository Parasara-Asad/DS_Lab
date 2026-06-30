#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *Link;
};

struct node *first = NULL;

int main()
{
    struct node *newnode, *temp;
    temp = newnode;
    int n;
    printf("HOw many data: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->info);
        newnode->Link = NULL;
        if (first == NULL)
        {
            first = newnode;
            temp = first;
        }
        else
        {
            temp->Link = newnode;
            temp = newnode;
        }
    }
    temp = first;

    printf("Data are: ");
    while (temp != NULL)
    {
        printf("%d ", temp->info);
        temp = temp->Link;
    }

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