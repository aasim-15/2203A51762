#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int* parse_priority_numbers(char* input, int* size) {
    int* numbers = (int*) malloc(strlen(input) * sizeof(int));
    if (numbers == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    char* token = strtok(input, ",");
    int count = 0;

    while (token != NULL) {
        numbers[count++] = atoi(token);
        token = strtok(NULL, ",");
    }
    *size = count;
    return numbers;
}

int main() {
    char input[256];
    int* priority_numbers;
    int size;

    printf("Enter orders Priority Number (comma-separated):\n");
    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = 0;

    priority_numbers = parse_priority_numbers(input, &size);
    if (priority_numbers == NULL) {
        return 1;
    }
    qsort(priority_numbers, size, sizeof(int), compare);
    printf("After Sorting Orders Priority:\n");
    for (int i = 0; i < size; i++) {
        printf("%d", priority_numbers[i]);
        if (i < size - 1) {
            printf(",");
        }
    }
    printf("\n");
    free(priority_numbers);
    return 0;
}

