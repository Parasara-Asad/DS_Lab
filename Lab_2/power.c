#include <stdio.h>

int main(){
    int base,power,ans=1;
    printf("Enter base number is: ");
    scanf("%d",&base);
    printf("Enter power number is: ");
    scanf("%d",&power);
    for (int i = 1; i <= power; i++)
    {
        ans = base * power;
    }
    printf("Answer is: %d",ans);
    
    return 0;
}
