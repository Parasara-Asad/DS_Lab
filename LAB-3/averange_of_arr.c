#include <stdio.h>

int main(){
    int size,sum=0;
    float averange;
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
        sum += arr[i];
    }
    averange = (float)sum/size;
    printf("Averange is: %.2f",averange);
    return 0;
}