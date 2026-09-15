#include<stdio.h>
#include<stdlib.h>
struct Node{
    int info;
    struct Node* next;
};

void main(){
    struct Node* head;
    struct Node* n=head;
    while(n->next!=NULL){
        printf("\nEnter Element:");
        scanf("%d",n->info);
    }
}