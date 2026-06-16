#include <stdio.h>

int main(){
    int size;
    printf("Enter Arry Size is: ");
    scanf("%d",&size);
    int arr[size];
    for(int i=0; i<size; i++)
    {
        printf("Enter Number %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    int find,replace,index=0;
    printf("Enter find number is: ");
    scanf("%d",&find);
    printf("Enter replace number is: ");
    scanf("%d",&replace);
    for(int i = 0; i < size; i++)
    {
        if (find == arr[i])
        {
            arr[i] = replace;
            index = i;
        }
        
    }
    if (index)
    {
    printf("Index of replace is: %d\n",index);
    printf("Arrary is: \n");
    for(int i = 0; i < size; i++)
    {
        printf("%d\n",arr[i]);
    }
    }
    else
    {
        printf("Value not found");
    }

    return 0;
}

