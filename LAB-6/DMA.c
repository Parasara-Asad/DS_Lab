#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ip;
    float *fp;
    char *cp;

    ip = (int *)malloc(sizeof(int));
    fp = (float *)malloc(sizeof(float));
    cp = (char *)malloc(sizeof(char));

    printf("Enter an integer: ");
    scanf("%d", ip);

    printf("Enter a float: ");
    scanf("%f", fp);

    printf("Enter a character: ");
    scanf(" %c", cp);

    printf("\nInteger = %d\n", *ip);
    printf("Float = %.2f\n", *fp);
    printf("Character = %c\n", *cp);

    free(ip);
    free(fp);
    free(cp);

    return 0;
}