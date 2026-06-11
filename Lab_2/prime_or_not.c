#include <stdio.h>

void prime_or_not(int n);

int main(){
    int n;
    printf("Enter Number is: ");
    scanf("%d",&n);
    prime_or_not(n);
    return 0;
}

void prime_or_not(int n){
    int conunt=0;
    for (int i = 1; i <= n; i++)
    {
        if(n%i==0){
            conunt++;
           
        }
    }
    if(conunt == 2){
        printf("Number is prime");
    }
    else
    {
        printf("Number is not prime");
    }
    
    
}