#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int* parse_product_ids(char* input, int* size) {
    int* ids = (int*) malloc(strlen(input) * sizeof(int));
    if (ids == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    char* token = strtok(input, ",");
    int count = 0;

    while (token != NULL) {
        ids[count++] = atoi(token);
        token = strtok(NULL, ",");
    }

    *size = count;
    return ids;
}

int main() {
    char input[256];
    int* product_ids;
    int size;
    printf("Enter Product IDs (comma-separated):\n");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;
    product_ids = parse_product_ids(input, &size);
    if (product_ids == NULL) {
        return 1;
    }
    qsort(product_ids, size, sizeof(int), compare);
    printf("After Sorting Product IDs:\n");
    for (int i = 0; i < size; i++) {
        printf("%d", product_ids[i]);
        if (i < size - 1) {
            printf(",");
        }
    }
    printf("\n");
    free(product_ids);
    return 0;
}

