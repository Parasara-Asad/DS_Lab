#include <stdio.h>

int main()
{
    int a, b, c;
    printf("Enter a is: ");
    scanf("%d", &a);
    printf("Enter b is: ");
    scanf("%d", &b);
    printf("Enter c is: ");
    scanf("%d", &c);
    int ans = (a >= b && b >= c) ? a : (b >= c && b >= a) ? b : c;
    printf("largest Number is: %d",ans);
    return 0;
}