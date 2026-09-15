#include <stdio.h>

    int top=-1;
    int stack[1000];
void push(int val){
    if(top>=1000){
        printf("stack is overflow");
    }
    top++;
    stack[top]=val;
}
int pop(){
    int val=stack[top];
    top--;
    return val;
}
void display(){
    while(top!=-1){
        printf("Element : %d\n",stack[top]);
        top--;
    }
}
void peep(int index){
    if(index<0 || index > top){
        printf("invalid index!");
    }
    printf("Element at %d is %d \n",index,stack[index]);
}
void change(int index,int val){
     if(index<0 || index > top){
        printf("invalid index!");
    }
    stack[index]=val;

}
void main(){
    //push method
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60);
    //pop method
    printf("poped element : %d\n",pop());
    //peep method
    peep(2); 
    //change method
change(2,100);   
    printf("stack after pop operation \n");
    //display method
    display();

}