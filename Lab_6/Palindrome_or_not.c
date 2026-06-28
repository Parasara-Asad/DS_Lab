#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    char *start, *end;

    printf("Enter a string: ");
    scanf("%s", str);

    start = str;
    end = str + strlen(str) - 1;

    while(start < end)
    {
        if(*start != *end)
        {
            printf("String is not Palindrome");
            return 0;
        }

        start++;
        end--;
    }

    printf("String is Palindrome");

    return 0;
}