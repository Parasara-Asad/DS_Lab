#include <stdio.h>
#include <stdlib.h>
struct Node *First = NULL;

struct Node
{
    int info;
    struct Node *link;
};
void remove_duplicate(struct Node *head)
{
    struct Node *ptr1,*ptr2,*dup;
    ptr1=head;
    while(ptr1!=NULL&&ptr1->link!=NULL){
        ptr2=ptr1;
        while(ptr2->link!=NULL){
            if(ptr1->info==ptr2->link->info){
                dup=ptr2->link;
                ptr2->link=ptr2->link->link;
                free(dup);
            }
            else{
                ptr2=ptr2->link;
            }
        }
        ptr1=ptr1->link;
    }
    struct Node *newHead=head;
    while(newHead->link!=NULL){
        printf("element: %d\n",newHead->info);
        newHead=newHead->link;
    }
    printf("element: %d\n",newHead->info);
}
void main()
{
    struct Node *L1_1 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *L1_2 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *L1_3 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *L1_4 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *L1_5 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *L1_6 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *head = L1_1;
    L1_1->info = 10;
    L1_1->link = L1_2;
    L1_2->info = 20;
    L1_2->link = L1_3;
    L1_3->info = 30;
    L1_3->link = L1_4;
    L1_4->info = 30;
    L1_4->link = L1_5;
    L1_5->info = 30;
    L1_5->link = L1_6;

    L1_6->info = 60;
    L1_6->link = NULL;

    remove_duplicate(head);

}