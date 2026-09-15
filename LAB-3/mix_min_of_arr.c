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
    int max = arr[0];
    int min = arr[0];
    for(int i = 0; i < size; i++)
    {
        if (arr[i] > arr[i+1])
        {
            max=arr[i];
        }
        if (arr[i] < arr[i+1])
        {
            min = arr[i];
        }
        
    }
    printf("Max value is: %d\nmin value is: %d",max,min);
    return 0;
}