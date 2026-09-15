#include <stdio.h>

int main(){
    int size,flag=0;
    printf("Enter Arry Size is: ");
    scanf("%d",&size);
    int arr[size];
    for(int i=0; i<size; i++)
    {
        printf("Enter Number %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    for(int i = 0; i < size; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                flag = 1;
                break;
            }
            
        }
    }
    if (flag)
    {
        printf("Arrary have duplicate values");
    }
    else{   
        printf("Arrary have not duplicate values");
    }
    
    return 0;
}