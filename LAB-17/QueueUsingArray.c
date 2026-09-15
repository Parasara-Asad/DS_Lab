#include <stdio.h>
int front=-1;
int rear=-1;
int Q[10];
int Enqueue(int val){
    if(rear==10){
        printf("Queue is overflow\n");
        return 0;
    }
    Q[rear]=val;
    rear++;
}
int Dequeue(){
    if(rear==-1){
        printf("Queue is underflow\n");
        return 0;
    }
    int val=Q[front];
    front++;
    return val;
}
void display(){
    if(front==rear){
        printf("Queue is empty\n");
    }
    for(int i=front;i<rear;i++){
        printf("Element : %d\n",Q[i]);
    }
}
void main(){
    Enqueue(10);
    Enqueue(20);
    Enqueue(30);
    Enqueue(40);
    Enqueue(50);
    Enqueue(60);
    Enqueue(70);
    Enqueue(80);
    Enqueue(90);
    Enqueue(100);
    printf("deleted Element : %d\n",Dequeue());
    printf("deleted Element : %d\n",Dequeue());
    printf("deleted Element : %d\n",Dequeue());
    printf("deleted Element : %d\n",Dequeue());
    display();
}