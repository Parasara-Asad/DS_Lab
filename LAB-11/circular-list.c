#include<stdio.h>
#include<stdlib.h>
struct Node{
    int info;
    struct Node *next;
};

struct Node *First;
//insert at first position in list
void insertatfront(struct Node *head,int val){
    struct Node* New=(struct Node*)malloc(sizeof(struct Node));
    struct Node *ptr=head;
    while(ptr->next=head){
        ptr=ptr->next;
    }
    New->info=val;
    New->next=ptr->next;
    ptr->next=New;
    head=New;
}
//delete at specific position you enter in code 
int deleteatposition(struct Node *head,int pos){
    struct Node *save=head;
    struct Node *prev=NULL;
    int i=1;
    while(i!=pos&&prev->next!=head){
        prev=save;
        save=save->next;
        i++;
    }
    if(prev->next==head){
        printf("invalid position\n");
        return 0;
    }
    prev->next=save->next;
    save->next=NULL;
    free(save);
    printf("Node deleted succesully\n");
    
}
//insert at end position in list
void insertatend(struct Node *head,int val){
    struct Node* New=(struct Node*)malloc(sizeof(struct Node));
    struct Node *save=head;
    while(save->next!=head){
        save=save->next;
    }
    New->info=val;
    New->next=save->next;
    save->next=New;
}
//display or print all node in list after upper opration can implement
void display(struct Node *head){
    struct Node *ptr=head;
    while(ptr->next!=head){
        printf("Element : %d\n",ptr->info);
        ptr=ptr->next;
    }
    printf("Element : %d",ptr->info);
}
//main method here start
void main(){
   
    struct Node* n1=(struct Node*)malloc(sizeof(struct Node));
    struct Node* n2=(struct Node*)malloc(sizeof(struct Node));
    struct Node* n3=(struct Node*)malloc(sizeof(struct Node));
    struct Node* n4=(struct Node*)malloc(sizeof(struct Node));
    struct Node* n5=(struct Node*)malloc(sizeof(struct Node));
    First=n1;
    n1->info=12;
    n2->info=23;
    n3->info=34;
    n4->info=54;
    n5->info=67;
    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=n5;
    n5->next=n1;

// here any number or int are enter by you ,you can enter any int in code 
    insertatend(First,100);//here 100 is any int you enter
    insertatfront(First,12);//here 12 is any int you enter
    deleteatposition(First,9);//here 9 is any int you enter
    display(First);//print all node of list quickly after uper opration

    //warning : you can use any one opration at a time (baki na ne comment ma nakhi deva)
}