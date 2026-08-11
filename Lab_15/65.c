#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

int F(char ch) {   
    switch (ch) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 3;
        case '^': return 6; 
        case '(': return 0;
        case ')': return 0;
        default:
            if (isalnum(ch)) return 7;
    }
    return -1;
}

int G(char ch) {  
    switch (ch) {
        case '+':
        case '-': return 2;
        case '*':
        case '/': return 4;
        case '^': return 5;
        case '(': return 9;
        case ')': return 0;
        default:
            if (isalnum(ch)) return 8;
    }
    return -1;
}

int R(char ch) {   // Rank Function
    if (isalnum(ch))
        return 1;
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        return -1;
    return 0;
}

void push(char ch) {
    stack[++top] = ch;
}

char pop() {
    return stack[top--];
}

int main() {
    char infix[MAX], postfix[MAX];
    int rank = 0, k = 0;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    // Initialize stack with '('
    push('(');

    // Append ')' to input
    strcat(infix, ")");

    int i = 0;
    char next = infix[i];

    while (next != '\0') {

        while (F(stack[top]) > G(next)) {
            char temp = pop();
            postfix[k++] = temp;

            rank += R(temp);

            if (rank < 1) {
                printf("INVALID Expression\n");
                return 0;
            }
        }

        if (F(stack[top]) != G(next)) {
            push(next);
        } else {
            pop();      // Matching parentheses
        }

        next = infix[++i];
    }

    postfix[k] = '\0';

    if (top != -1 || rank != 1)
        printf("INVALID Expression\n");
    else
        printf("Postfix Expression: %s\n", postfix);

    return 0;
}