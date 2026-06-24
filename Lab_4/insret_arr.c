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
    printf("Array is: ");
    for(int i = 0; i < size; i++)
    {
        printf(" %d",arr[i]);
    }
    int index;
    printf("Enter how index insert: ");
    scanf("%d",&index);
    
    return 0;
}