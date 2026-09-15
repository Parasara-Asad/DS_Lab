#include<stdio.h>
#include<string.h>
int top=-1;
char s[100];
void push(char c){
    top++;
    s[top]=c;
}
void display(){
    while(1){
        if(top==-1){
            break;
        }
        printf("%c",s[top]);
        top--;
    }
}
void RemoveStar(char str[]){
    int c=0;
    int size=strlen(str);
    int i=size-1;
    while(i!=-1){
        if(str[i]=='*'){
            c++;
            i--;
            continue;
        }
        else{
            if(c!=0){
                c--;
                i--;
                continue;
            }
            else{
                push(str[i]);
                i--;
                continue;
            }
        }
    }
   display();
}
void main(){
    char str[100];
    printf("Enter Input : ");
    scanf("%s",str);
    RemoveStar(str);
}