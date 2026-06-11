#include <stdio.h>

int main(){
    int n,ans=1;
    printf("Enter Number is: ");
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        ans = ans * i;
    }
    printf("Answer is: %d",ans);
    
    return 0;
}