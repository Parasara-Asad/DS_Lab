#include <stdio.h>

int main(){
    int Year;
    printf("Enter the year is: ");
    scanf("%d",&Year);
    if(Year%400==0 || Year%4==0 && Year%100!=0){
        printf("Year is leap");
    }
    else{
        printf("Year is not leap");
    }
    return 0;
}