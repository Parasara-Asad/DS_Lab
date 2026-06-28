#include <stdio.h>

int main()
{
    int arr[100], n, i;
    int *ptr, max;

    printf("Enter array size: ");
    scanf("%d", &n);

    ptr = arr;

    printf("Enter array elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", ptr + i);
    }

    max = *ptr;

    for(i = 1; i < n; i++)
    {
        if(*(ptr + i) > max)
        {
            max = *(ptr + i);
        }
    }

    printf("Largest element = %d", max);

    return 0;
}