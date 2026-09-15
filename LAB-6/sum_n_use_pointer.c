#include <stdio.h>

int main()
{
    int arr[100], n, i, sum = 0;
    int *ptr;

    printf("Enter array size: ");
    scanf("%d", &n);

    ptr = arr;

    printf("Enter %d numbers:\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", ptr + i);
    }

    for(i = 0; i < n; i++)
    {
        sum += *(ptr + i);
    }

    printf("Sum = %d", sum);

    return 0;
}