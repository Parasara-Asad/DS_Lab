#include<stdio.h>
#include<string.h>
#include<ctype.h>
char stack[100];
int top=-1;
void push(char x){
    top++;
    stack[top]=x;
}
int pop(){
    char c =stack[top];
    top--;  
    return c;  
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
void InfixToPostfix(char infix[]){
    int i=0;
    int j=0;
    char postficExp[100];
    
    while(infix[i]!='\0'){
        if(isalpha(infix[i])){
            postficExp[j]=infix[i];
            j++;
          
        }
        if(isalnum(infix[i])){
            if(input_pre(infix[i])>stack_pre(stack[top])||input_pre(infix[i])!=stack_pre(stack[top])){
                push(infix[i]);
            }
            else{
                postficExp[j]=pop();
            }

        }
        i++;
    }
    postficExp[j]='\0';
    printf("%s",postficExp);
}
void main(){
    char infix[100];
    printf("enter infix Expresion : ");
    scanf("%s",infix);
    InfixToPostfix(infix);
}