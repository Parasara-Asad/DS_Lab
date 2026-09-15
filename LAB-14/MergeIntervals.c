#include <stdio.h>
#include <stdlib.h>

struct Interval {
    int start;
    int end;
};

int compareInterval(const void* a, const void* b) {
    return ((struct Interval*)a)->start - ((struct Interval*)b)->start;
}

int main() {
    int n;
    printf("Enter number of intervals: ");
    scanf("%d", &n);
    struct Interval arr[n];
    for (int i = 0; i < n; i++) {
        printf("Enter start and end of interval %d: ", i + 1);
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }
    
    qsort(arr, n, sizeof(struct Interval), compareInterval);
    
    int index = 0;
    for (int i = 1; i < n; i++) {
        if (arr[index].end >= arr[i].start) {
            if (arr[index].end < arr[i].end) {
                arr[index].end = arr[i].end;
            }
        } else {
            index++;
            arr[index] = arr[i];
        }
    }
    
    printf("\nMerged Intervals: ");
    for (int i = 0; i <= index; i++) {
        printf("{%d, %d} ", arr[i].start, arr[i].end);
    }
    printf("\n");
    return 0;
}
