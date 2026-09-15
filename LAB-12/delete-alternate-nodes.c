#include<stdio.h>
#include<stdlib.h>
struct Node{
    int info;
    struct Node *LP;
    struct Node *RP;
};
struct Node *First;
void deletealter(struct Node *head){
    printf("List Before Delete Alternative Nodes\n");
    struct Node *ptr=head;
    while(ptr->RP!=NULL){
             printf("Element : %d\n",ptr->info);
             ptr=ptr->RP;
         }printf("Element : %d\n",ptr->info);
        struct Node *prev=head;
        struct Node *adrs;
        while(prev->RP!=NULL){
        struct Node *save=prev->RP;
            
            adrs=save->RP;
            adrs->LP=prev->RP;
            prev->RP=save->RP;
            prev=adrs;
            free(save);
        }
        prev->RP=NULL;
        ptr=head;
    printf("List After Delete Alternative Nodes\n");

    while(ptr->RP!=NULL){
        printf("Element : %d\n",ptr->info);
        ptr=ptr->RP;
    }printf("Element : %d\n",ptr->info);
}
void main(){
    struct Node* n1=(struct Node*)malloc(sizeof(struct Node));
    struct Node* n2=(struct Node*)malloc(sizeof(struct Node));
    struct Node* n3=(struct Node*)malloc(sizeof(struct Node));
    struct Node* n4=(struct Node*)malloc(sizeof(struct Node));
    struct Node* n5=(struct Node*)malloc(sizeof(struct Node));
    struct Node* n6=(struct Node*)malloc(sizeof(struct Node));
    struct Node* n7=(struct Node*)malloc(sizeof(struct Node));
    First=n1;
    n1->info=10;
    n2->info=20;
    n3->info=30;
    n4->info=40;
    n5->info=50;
    n6->info=60;
    n7->info=70;

    n1->LP=NULL;
    n2->LP=n1;
    n3->LP=n2;
    n4->LP=n3;
    n5->LP=n4;
    n6->LP=n5;
    n7->LP=n6;

    n1->RP=n2;
    n2->RP=n3;
    n3->RP=n4;
    n4->RP=n5;
    n5->RP=n6;
    n6->RP=n7;
    n7->RP=NULL;


    deletealter(First);
}