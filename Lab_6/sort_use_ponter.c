#include <stdio.h>

int main()
{
    int arr[100], n, i, j, temp;
    int *ptr;

    printf("Enter array size: ");
    scanf("%d", &n);

    ptr = arr;

    printf("Enter array elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", ptr + i);
    }

    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(*(ptr + j) > *(ptr + j + 1))
            {
                temp = *(ptr + j);
                *(ptr + j) = *(ptr + j + 1);
                *(ptr + j + 1) = temp;
            }
        }
    }

    printf("Sorted array:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", *(ptr + i));
    }

    return 0;
}