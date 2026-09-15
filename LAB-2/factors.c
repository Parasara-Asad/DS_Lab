#include <stdio.h>

int main(){
    int n;
    printf("Enter number is: ");
    scanf("%d",&n);
    printf("Faxtor is: ");
    for(int i = 1; i <= n; i++)
    {
        if (i%2==0)
        {
            printf(" %d",i);
        }
        
    }
    return 0;
}
