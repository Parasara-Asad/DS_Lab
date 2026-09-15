#include<stdio.h>
#include<stdlib.h>
struct Node{
    int info;
    struct Node* next;
}; struct Node* top=NULL;
void display(struct Node *top){
    struct Node *ptr;
    ptr=top;
    if(ptr==NULL){
        printf("stack is empty");
    }
    while(ptr->next!=NULL){
        printf("Element : %d\n",ptr->info);
        ptr=ptr->next;
    }printf("Element : %d\n",ptr->info);
}
void main(){
    struct Node* s1=(struct Node*)malloc(sizeof(struct Node));
    struct Node* s2=(struct Node*)malloc(sizeof(struct Node));
    struct Node* s3=(struct Node*)malloc(sizeof(struct Node));
    struct Node* s4=(struct Node*)malloc(sizeof(struct Node));
    struct Node* s5=(struct Node*)malloc(sizeof(struct Node));
    s1->info=50;
    s2->info=40;
    s3->info=30;
    s4->info=20;
    s5->info=10;
    top=s1;
    s1->next=s2;
    s2->next=s3;
    s3->next=s4;
    s4->next=s5;
    s5->next=NULL;

    display(top);
}