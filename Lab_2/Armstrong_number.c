#include <stdio.h>

/*
  Armstrong number is
  Ex:153
  3 digit all power has 3 ans all sum
  if sum equal to number is Armstrong
  or not Armstrong
*/
void is_Armstrong(int n);
int main()
{
    int s, e;
    printf("Enter number start is: ");
    scanf("%d", &s);
    printf("Enter number ens is: ");
    scanf("%d", &e);
    for (int i = s; i <= e; i++)
    {
        is_Armstrong(i);
    }
    return 0;
}

void is_Armstrong(int n)
{
    int N, count = 0, temp1 = n, temp2 = n;
    int sum = 0;
    while (n != 0)
    {
        N = n % 10;
        count++;
        n = n / 10;
    }
    while (temp1 != 0)
    {
        N = temp1 % 10;
        int ans = 1;
        for (int i = 1; i <= count; i++)
        {
            ans *= N;
        }
        sum += ans;
        temp1 = temp1 / 10;
    }
    if (sum == temp2)
    {
        printf(" %d", temp2);
    }
}