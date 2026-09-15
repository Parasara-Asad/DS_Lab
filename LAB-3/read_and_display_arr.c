#include <stdio.h>

int main(){
    int n;
    printf("Enter Arry Size is: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0; i<n; i++)
    {
        printf("Enter Number %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("Arrary is: \n");
    for(int i = 0; i < n; i++)
    {
        printf(" %d\n",arr[i]);    
    }
    return 0;
}