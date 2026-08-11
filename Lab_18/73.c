#include <stdio.h>

#define MAX 5

int deque[MAX];
int f = -1, r = -1;

void insertf(int x)
{
    if ((f == 0 && r == MAX - 1) || (f == r + 1))
    {
        printf("Deque Overflow\n");
        return;
    }

    if (f == -1)
    {
        f = r = 0;
    }
    else if (f == 0)
    {
        f = MAX - 1;
    }
    else
    {
        f--;
    }

    deque[f] = x;
}

void insertr(int x)
{
    if ((f == 0 && r == MAX - 1) || (f == r + 1))
    {
        printf("Deque Overflow\n");
        return;
    }

    if (f == -1)
    {
        f = r = 0;
    }
    else if (r == MAX - 1)
    {
        r = 0;
    }
    else
    {
        r++;
    }

    deque[r] = x;
}

void deletef()
{
    if (f == -1)
    {
        printf("Deque Underflow\n");
        return;
    }

    printf("Deleted element: %d\n", deque[f]);

    if (f == r)
    {
        f = r = -1;
    }
    else if (f == MAX - 1)
    {
        f = 0;
    }
    else
    {
        f++;
    }
}

void deleter()
{
    if (f == -1)
    {
        printf("Deque Underflow\n");
        return;
    }

    printf("Deleted element: %d\n", deque[r]);

    if (f == r)
    {
        f = r = -1;
    }
    else if (r == 0)
    {
        r = MAX - 1;
    }
    else
    {
        r--;
    }
}

void display()
{
    if (f == -1)
    {
        printf("Deque is Empty\n");
        return;
    }

    int i = f;
    printf("Deque Elements: ");

    while (1)
    {
        printf("%d ", deque[i]);

        if (i == r){
            break;
        }
        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main()
{
    int choice, x;

    do
    {
        printf("\n--- DEQUE MENU ---\n");
        printf("1. Insert at f\n");
        printf("2. Insert at r\n");
        printf("3. Delete from f\n");
        printf("4. Delete from r\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter x: ");
            scanf("%d", &x);
            insertf(x);
            break;

        case 2:
            printf("Enter x: ");
            scanf("%d", &x);
            insertr(x);
            break;

        case 3:
            deletef();
            break;

        case 4:
            deleter();
            break;

        case 5:
            display();
            break;

        case 6:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid Choice\n");
        }

    } while (choice != 6);

    return 0;
}