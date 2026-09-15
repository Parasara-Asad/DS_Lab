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
void evaluation_postfix(char prefix[100]){
    for(int i=0;i<strlen(prefix);i++){
        if(isdigit(prefix[i])){
            push(prefix[i] - '0');
        }
        else{
            int opar1=pop();
            int opar2=pop();
            switch (prefix[i]){
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
    char prefix[100];
    printf("Enter Postfix Expression : ");
    scanf("%s",prefix);
    strrev(prefix);
    evaluation_postfix(prefix);
    printf("Ans : %d",pop());
}