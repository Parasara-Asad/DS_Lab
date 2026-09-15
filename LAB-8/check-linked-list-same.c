#include <stdio.h>
#include <stdlib.h>
struct Node *First = NULL;

struct Node
{
    int info;
    struct Node *link;
};
int checksame(struct Node *list1, struct Node *list2)
{
    while(list1!=NULL){
        
            if(list1->info!=list2->info){
                return 0;
                break;
            }else{

                list2=list2->link;
            }
            list1=list1->link;
        }
        return 1;
    }

void main()
{
    struct Node *L1_1 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *L1_2 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *L1_3 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *L1_4 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *L1_5 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *L1_6 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *L2_1 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *L2_2 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *L2_3 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *L2_4 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *L2_5 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *L2_6 = (struct Node *)malloc(sizeof(struct Node));
    L1_1->info = 10;
    L1_1->link = L1_2;
    L1_2->info = 20;
    L1_2->link = L1_3;
    L1_3->info = 30;
    L1_3->link = L1_4;
    L1_4->info = 40;
    L1_4->link = L1_5;
    L1_5->info = 50;
    L1_5->link = L1_6;

    L1_6->info = 60;
    L1_6->link = NULL;

    L2_1->info = 10;
    L2_1->link = L2_2;

    L2_2->info = 20;
    L2_2->link = L2_3;

    L2_3->info = 30;
    L2_3->link = L2_4;

    L2_4->info = 50;
    L2_4->link = L2_5;

    L2_5->info = 50;
    L2_5->link = L2_6;

    L2_6->info = 60;
    L2_6->link = NULL;

    int ans = checksame(L1_1, L2_1);
    if (ans == 1)
    {
        printf("both linked list are same");
    }
    else
    {
        printf("both linked list are not same");
    }
}