#include <stdio.h>

#define MAX 5

int Q[MAX], priority[MAX];
int n = 0;

void insert(int val, int p)
{
    if (n == MAX)
    {
        printf("Queue Overflow\n");
        return;
    }

    int i = n - 1;

    while (i >= 0 && priority[i] < p)
    {
        Q[i + 1] = Q[i];
        priority[i + 1] = priority[i];
        i--;
    }

    Q[i + 1] = val;
    priority[i + 1] = p;
    n++;
}

void delete ()
{
    if (n == 0)
    {
        printf("Queue Underflow\n");
        return;
    }

    printf("Deleted Element = %d\n", Q[0]);

    for (int i = 0; i < n - 1; i++)
    {
        Q[i] = Q[i + 1];
        priority[i] = priority[i + 1];
    }

    n--;
}

void display()
{
    if (n == 0)
    {
        printf("Queue is Empty\n");
        return;
    }

    printf("\nElement\tPriority\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\n", Q[i], priority[i]);
    }
}

int main()
{
    int ch, value, p;

    while (1)
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter Element: ");
            scanf("%d", &value);
            printf("Enter Priority: ");
            scanf("%d", &p);
            insert(value, p);
            break;

        case 2:
            delete();
            break;

        case 3:
            display();
            break;

        case 4:
            return 0;    

        default:
            printf("Invalid Choice\n");
        }
    }
}