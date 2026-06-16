#include <stdio.h>
void prime_Numbers(int n);
int main()
{
    int s, e;
    printf("Enter start number is: ");
    scanf("%d", &s);
    printf("Enter end number is: ");
    scanf("%d", &e);
    for (int i = s; i <= e; i++)
    {
        prime_Numbers(i);
    }

    return 0;
}

void prime_Numbers(int n)
{
    int conunt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            conunt++;
        }
    }
    if (conunt == 2)
    {
        printf(" %d", n);
    }
}
