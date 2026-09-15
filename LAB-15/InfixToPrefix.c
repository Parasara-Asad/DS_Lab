#include <stdio.h>
#include <string.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    if (top == -1) return -1;
    return stack[top--];
}

int precedence(char x) {
    if (x == '(') return 0;
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    if (x == '^') return 3;
    return 0;
}

void reverse(char* exp) {
    int n = strlen(exp);
    for (int i = 0; i < n / 2; i++) {
        char temp = exp[i];
        exp[i] = exp[n - i - 1];
        exp[n - i - 1] = temp;
    }
}

int main() {
    char exp[100];
    char res[100];
    int j = 0;
    
    printf("Enter infix expression: ");
    scanf("%s", exp);
    
    reverse(exp);
    
    for (int i = 0; i < strlen(exp); i++) {
        if (exp[i] == '(') {
            exp[i] = ')';
        } else if (exp[i] == ')') {
            exp[i] = '(';
        }
    }
    
    for (int i = 0; i < strlen(exp); i++) {
        if (isalnum(exp[i])) {
            res[j++] = exp[i];
        } else if (exp[i] == '(') {
            push(exp[i]);
        } else if (exp[i] == ')') {
            while (top != -1 && stack[top] != '(') {
                res[j++] = pop();
            }
            pop();
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(exp[i])) {
                res[j++] = pop();
            }
            push(exp[i]);
        }
    }
    
    while (top != -1) {
        res[j++] = pop();
    }
    res[j] = '\0';
    
    reverse(res);
    
    printf("Prefix expression: %s\n", res);
    return 0;
}
