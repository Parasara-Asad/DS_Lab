#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
int stack[100];
int top=-1;
void push(int n){
    top++;
    stack[top]=n;
}
int pop(){
    int no=stack[top];
    top--;
    return no;
}
void evaluation_postfix(char postfix[100]){
    for(int i=0;i<strlen(postfix);i++){
        if(isdigit(postfix[i])){
            push(postfix[i] - '0');
        }
        else{
            int opar2=pop();
            int opar1=pop();
            switch (postfix[i]){
                case '+':
                push(opar1+opar2);
                break;

                case '-':
                push(opar1-opar2);
                break;

                case '*':
                push(opar1*opar2);
                break;

                case '/':
                push(opar1/opar2);
                break;

                case '^':
                push(pow(opar1,opar2));
                break;
            }
        
        }
    }
}
void main(){
    char postfix[100];
    printf("Enter Postfix Expression : ");
    scanf("%s",postfix);
    evaluation_postfix(postfix);
    printf("Ans : %d",pop());
}