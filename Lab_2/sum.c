#include <stdio.h>

int main()
{
    int n, ans = 0;
    printf("Enter how many number: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        for (int j = 1; j <= i; j++)
        {
            sum += j;
        }
        ans += sum;
    }
    printf("Answer is: %d", ans);

    return 0;
}