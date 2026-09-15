#include <stdio.h>

int main()
{
    char ch;
    printf("Enter the charecter is: ");
    scanf("%c", &ch);
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch =='U')
    {
        printf("Charecter is vowel");
    }
    else
    {
        printf("Charecter is not vowel");
    }
    

    return 0;
}