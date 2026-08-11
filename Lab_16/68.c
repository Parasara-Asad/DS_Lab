#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int stack[100];
int top = -1;

void push(int n)
{
    stack[++top] = n;
}

int pop()
{
    return stack[top--];
}

int evaluate(char prefix[])
{
    int op1, op2;

    for (int i = 0; prefix[i] != '\0'; i++)
    {
        if (isdigit(prefix[i]))
        {
            push(prefix[i] - '0');
        }
        else
        {
            op1 = pop();
            op2 = pop();

            switch (prefix[i])
            {
            case '+':
                push(op1 + op2);
                break;

            case '-':
                push(op1 - op2);
                break;

            case '*':
                push(op1 * op2);
                break;

            case '/':
                push(op1 / op2);
                break;

            case '^':
                push((int)pow(op1, op2));
                break;
            }
        }
    }

    return pop();
}

int main()
{
    char prefix[100];

    printf("Enter prefix expression: ");
    scanf("%s", prefix);
    strrev(prefix);
    printf("Answer is: %d\n", evaluate(prefix));

    return 0;
}