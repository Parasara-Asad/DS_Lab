#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main()
{
    int T;
    scanf("%d", &T);

    while (T--)
    {
        int N;
        scanf("%d", &N);

        int A[N], sorted[N], stack[N];
        int top = -1;

        for (int i = 0; i < N; i++)
        {
            scanf("%d", &A[i]);
            sorted[i] = A[i];
        }

        qsort(sorted, N, sizeof(int), cmp);

        int idx = 0;

        for (int i = 0; i < N; i++)
        {
            stack[++top] = A[i];

            while (top >= 0 && stack[top] == sorted[idx])
            {
                top--;
                idx++;
            }
        }

        if (idx == N)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}