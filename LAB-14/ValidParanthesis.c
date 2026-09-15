#include <stdio.h>
#include <string.h>
int top=-1;
char s[100];
void push(char c){
    top++;
    s[top]=c;
}
void pop(){
    top--;
}
int CheckValidation(char string[100]){
    int i=0;
    while(string[i]!='\0'){
        if(string[i]=='{'||string[i]=='['||string[i]=='('){
            push(s[i]);
            i++;
        }else if(string[i]=='}'&&s[top]=='{' || string[i]==']'&&s[top]=='[' || string[i]==')'&&s[top]=='('){
            pop();
            i++;
        }
       
    }
     if(top==-1){
            printf("1\n");
        }
        else{
            printf("0\n");
        }
}
void main(){
    int n;
    char string[100];
    printf("Enter n For How Many ParanthasString you Enter : ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        printf("Enter Paranths String : ");
        scanf("%s",string);
        CheckValidation(string);
    }
}