#include <stdio.h>
#include <stdlib.h>

int compare_asc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
int compare_desc(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

void process_delivery_times(int times[], int size, char order) {
    if (order == 'a') {
        qsort(times, size, sizeof(int), compare_asc);
    } else if (order == 'd') {
        qsort(times, size, sizeof(int), compare_desc);
    } else {
        printf("Invalid order specified. Use 'a' for ascending or 'd' for descending.\n");
        return;
    }

    for (int i = 0; i < size; i++) {
        printf("%d\n", times[i]);
    }
}

int main() {
    int n;
    char order;

    printf("Enter the number of delivery times: ");
    scanf("%d", &n);

    int *times = (int*) malloc(n * sizeof(int));
    if (times == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    printf("Enter the delivery times:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &times[i]);
    }
    printf("Enter the order of sorting (a for ascending, d for descending): ");
    scanf(" %c", &order);
    process_delivery_times(times, n, order);
    free(times);
    return 0;
}

