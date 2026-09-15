#include <stdio.h>
#include <string.h>
    int top=-1;
    int stack[1000];
void push(char c){
    if(top>=1000){
        printf("stack is overflow");
    }
    top++;
    stack[top]=c;
}
int pop(){
    char val=stack[top];
    top--;
    return val;
}
int CheckPalindrome(char s[100]){
    int i=0;
    int size=strlen(s);
    while(i<=size/2){
        push(s[i]);
        i++;
    }
    while(s[i]!='\0'){
        if(pop()!=s[i]){
            return 1;
          
        }
        i++;
    }
    return 0;
}
void main(){
    char s[100];
    printf("Enter A String : ");
    scanf("%s",s);
    int flag = CheckPalindrome(s);
    if(flag==0){
        printf("Palindrome");
    }
    else{
        printf("Not Palindrome");
    }
}