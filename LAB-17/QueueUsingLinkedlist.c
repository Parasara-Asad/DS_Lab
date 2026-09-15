#include <stdio.h>
#include <stdlib.h>
struct Node{
    int info;
    struct Node *next;
};
struct Node *First;
struct Node *Last;
void DleteAtFirst(){
    struct Node *ptr=First;
    First=ptr->next;
    printf("Deleted Element : %d\n",ptr->info);
    free(ptr);
}
void IndertAtEnd(int val){
   struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
   newNode->info=val;
   Last->next=newNode;
   Last=newNode;
}
void display(){
    struct Node *ptr=First;
    while(ptr=Last){
        printf("Element : %d\n",ptr->info);
        ptr=ptr->next;
    }
     printf("Element : %d\n",ptr->info);
}
void main(){
    struct Node* n1=(struct Node*)malloc(sizeof(struct Node));
    struct Node* n2=(struct Node*)malloc(sizeof(struct Node));
    struct Node* n3=(struct Node*)malloc(sizeof(struct Node));
    struct Node* n4=(struct Node*)malloc(sizeof(struct Node));
    struct Node* n5=(struct Node*)malloc(sizeof(struct Node));
    First=n1;
    Last=n5;
    n1->info=10;
    n2->info=20;
    n3->info=30;
    n4->info=40;
    n5->info=50;
    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=n5;
    n5->next=NULL;
    DleteAtFirst();
    IndertAtEnd(100);
    display();
}