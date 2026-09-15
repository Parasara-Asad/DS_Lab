#include <stdio.h>

int main(){
    int d;
    printf("Enter total days: ");
    scanf("%d",&d);
    int year,week,days;
    year = d/365;
    week = (d%365) / 7;
    days = (d%365) %7;
    printf(" Year: %d\n Weeks: %d\n Days: %d\n",year,week,days);
    return 0;
}