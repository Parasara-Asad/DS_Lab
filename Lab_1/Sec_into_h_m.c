#include <stdio.h>

int main(){
    int s;
    printf("Enter Sec is: ");
    scanf("%d",&s);
    int hour,min,sec;
    hour = s / 3600;
    min = (s % 3600) / 60 ;
    sec = s % 60;
    printf("%d : %d : %d",hour,min,sec);
    return 0;
}

// 60-1
// 3600-?
// 3600/60