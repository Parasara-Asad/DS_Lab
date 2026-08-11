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

int evaluate(char postfix[])
{
    int op1, op2;

    for (int i = 0; postfix[i] != '\0'; i++)
    {
        if (isdigit(postfix[i]))
        {
            push(postfix[i] - '0');
        }
        else
        {
            op2 = pop();
            op1 = pop();

            switch (postfix[i])
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
    char postfix[100];

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    printf("Answer is: %d\n", evaluate(postfix));

    return 0;
}