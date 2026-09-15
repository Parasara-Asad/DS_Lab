#include <stdio.h>
#include<stdbool.h>

int main(){
    int size;
    int search,flag=false,index;
    printf("Enter Arry Size is: ");
    scanf("%d",&size);
    int arr[size];
    for(int i=0; i<size; i++)
    {
        printf("Enter Number %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("Enter Search element is: ");
    scanf("%d",&search);
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == search)
        {
            flag = true;
            index = i;
            break;
        }
        
    }
    if (flag)
    {
        printf("Element is found index %d",index);
    }
    else
    {
        printf("Element not found");
    }
    
    
    
    return 0;
}