#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char word[20][50], ans[50];
    char temp1[50], temp2[50], t;
    int n, i, j, r;

    printf("Enter number of words: ");
    scanf("%d", &n);

    printf("Enter %d words:\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%s", word[i]);
    }

    srand(time(NULL));
    r = rand() % n;

    printf("Word: %s\n", word[r]);
    printf("Enter its anagram: ");
    scanf("%s", ans);

    if(strlen(word[r]) != strlen(ans))
    {
        printf("Not an Anagram");
        return 0;
    }

    strcpy(temp1, word[r]);
    strcpy(temp2, ans);

    for(i = 0; temp1[i] != '\0'; i++)
    {
        for(j = i + 1; temp1[j] != '\0'; j++)
        {
            if(temp1[i] > temp1[j])
            {
                t = temp1[i];
                temp1[i] = temp1[j];
                temp1[j] = t;
            }
        }
    }

    for(i = 0; temp2[i] != '\0'; i++)
    {
        for(j = i + 1; temp2[j] != '\0'; j++)
        {
            if(temp2[i] > temp2[j])
            {
                t = temp2[i];
                temp2[i] = temp2[j];
                temp2[j] = t;
            }
        }
    }

    if(strcmp(temp1, temp2) == 0)
        printf("Valid Anagram");
    else
        printf("Not an Anagram");

    return 0;
}