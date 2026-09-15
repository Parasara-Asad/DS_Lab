#include <stdio.h>
#include <string.h>

int isVowel(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return 1;
    return 0;
}

void reverseString(char* str, int start, int end) {
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        char s[n + 1];
        scanf("%s", s);
        
        for (int i = 0; i < n; i++) {
            if (isVowel(s[i])) {
                reverseString(s, 0, i - 1);
            }
        }
        
        printf("%s\n", s);
    }
    return 0;
}
