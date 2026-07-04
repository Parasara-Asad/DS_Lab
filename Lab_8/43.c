#include <stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *link;
};

struct node *first1 = NULL;
struct node *first2 = NULL;

void insertfirst1(int x){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = x;
    newnode->link = first1;
    first1 = newnode;
}
void insertfirst2(int x){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = x;
    newnode->link = first2;
    first2 = newnode;
}

void sameornot(){
    struct node *save1 = first1;
    struct node *save2 = first2;
    int issame = 0;
    while (save1 != NULL && save2 !=NULL)
    {
        if (save1->info !=save2->info)
        {
            printf("list is not same");
            issame=1;
            return;
        }
        save1 = save1->link;
        save2 = save2->link;
    }
    if (issame==0)
    {
        printf("List is same");
    }
    
    
    
    
}

void display(struct node *first){
    struct node *save;
    if (first == NULL)
    {
        printf("List is empty!");
        return;
    }
    save = first;
    while (save != NULL)
    {
        printf(" %d ",save->info);
        save = save->link;
    }
    printf("\n");
    
}

int main(){
    insertfirst1(1);
    insertfirst1(2);
    insertfirst1(3);
    insertfirst2(1);
    insertfirst2(5);
    insertfirst2(3);
    // display(first1);
    // display(first2);
    sameornot();
    return 0;
}