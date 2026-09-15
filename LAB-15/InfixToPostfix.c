#include <stdio.h>
#include<string.h>
#include<ctype.h>
char stack[100];
int top=-1;
void push(char x){
    stack[top++]=x;
}
int pop(){
    return stack[top--];    
}
int stack_pre(char c){
    if(c=='+'||c=='-'){
        return 2;
    }
    if(c=='*'||c=='/'){
        return 4;
    }
    if(c=='^'){
        return 5;
    }
    if(c=='('){
        return 0;
    }
    else{
        return 8;
    }
}

int input_pre(char c){
    if(c=='+'||c=='-'){
        return 1;
    }
    if(c=='*'||c=='/'){
        return 3;
    }
    if(c=='^'){
        return 6;
    }
    if(c=='('){
        return 0;
    }
    else{
        return 7;
    }
}
int rank(char temp){
    if(temp=='+'||temp=='-'||temp=='*'||temp=='/'||temp=='^'){
        return -1;
    }
    else{
        return 1;
    }
}
void revpol(char infix[]){
    int j=0;
    int i=0;
    int r=0;
    char postfixExp[100];
    push('(');
    while(i!=strlen(infix)){
        char next=infix[i];
        while(isalpha(next)){
            postfixExp[j]=next;
            j++;
            i++;
        }
        while(stack_pre(stack[top])>input_pre(infix[i])){
            char temp=pop();
            postfixExp[j++]=temp;
            r=r+rank(temp);
            if(r<1){
                printf("...Invalid...");
                return;
            }

        }
        if(stack_pre(stack[top])!=input_pre(next)){
            push(next);
        }
        else{
            char ch=pop();
            postfixExp[j++]=ch;
        }
        i++;
    }
    postfixExp[j]='\0';
    if(top!=-1||r!=1){
        printf("Invalid");
    }
    else{
        printf("Postfix Exp : %s",postfixExp);
    }
    
}
void main(){
    char infix[100];
    printf("enter infix Expresion : ");
    scanf("%s",infix);
    printf("Demo : %s",infix);
    revpol(infix);
}