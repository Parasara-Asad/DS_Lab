#include <stdio.h>

#define max 10

int stack[max];

int top = -1;

void push(int x)
{
    if (top == max - 1)
    {
        printf("Stake overflow");
    }
    else
    {
        top++;
        stack[top] = x;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Stack is empty!");
    }
    else
    {
        top--;
    }
}

void display()
{
    if (top == -1)
    {
        printf("Stack is empty");
    }
    else
    {
        for (int i = top; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main()
{
    push(5);
    push(3);
    push(2);
    push(1);
    printf("Stack is: ");
    display();
    printf("After pop Stack is: ");
    pop();
    display();

    return 0;
}