#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to sort names alphabetically
void sort_names(char (*names)[20], int n) {
    char temp[20];
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(names[j], names[j + 1]) > 0) {
                // Swap names[j] and names[j + 1]
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
        }
    }
}

int main() {
    int n;

    // Input the number of names
    printf("Enter the number of names: ");
    scanf("%d", &n);

    // Dynamically allocate memory for n names
    char (*names)[20] = malloc(n * sizeof(*names));
    if (names == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Input names
    printf("Enter %d names (maximum 20 characters each):\n", n);
    for (int i = 0; i < n; i++) {
        printf("[%d] -> ", i);
        scanf("%s", names[i]);
    }

    // Sort the names
    sort_names(names, n);

    // Print sorted names
    printf("\nThe sorted names are:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", names[i]);
    }

    // Free allocated memory
    free(names);

    return 0;
}
