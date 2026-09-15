#include <stdio.h>

int main() {
    int m, n, sum = 0;

    printf("Enter m: ");
    scanf("%d", &m);

    printf("Enter n: ");
    scanf("%d", &n);

    int size = n - m + 1;
    int arr[size];

    for (int i = 0; i < size; i++) {
        arr[i] = m + i;
        sum += arr[i];
    }

    printf("Sum = %d", sum);

    return 0;
}