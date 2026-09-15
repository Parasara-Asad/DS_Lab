#include <stdio.h>
#include <stdbool.h>

int main()
{
    int size;
    int search, left, right, mid;
    int flag = false, index;
    printf("Enter Arry Size is: ");
    scanf("%d", &size);
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        printf("Enter Number %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Enter Search element is: ");
    scanf("%d", &search);
    left = 0;
    right = size - 1;
    while (left <= right)
    {
        mid = (right + left) / 2;
        if (arr[mid] == search)
        {
            flag = true;
            index = mid;
            break;
        }
        else if (search <= arr[mid])
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    if (flag)
    {
        printf("Element is found index %d", index);
    }
    else
    {
        printf("Element not found");
    }

    return 0;
}