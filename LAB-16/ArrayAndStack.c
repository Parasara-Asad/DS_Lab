#include <stdio.h>
#include <stdlib.h>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int a[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        
        int stack[n];
        int top = -1;
        int expected = 1;
        
        for (int i = 0; i < n; i++) {
            while (top != -1 && stack[top] == expected) {
                top--;
                expected++;
            }
            if (a[i] == expected) {
                expected++;
            } else {
                stack[++top] = a[i];
            }
        }
        
        while (top != -1 && stack[top] == expected) {
            top--;
            expected++;
        }
        
        if (expected - 1 == n) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
