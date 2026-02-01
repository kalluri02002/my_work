#include <stdio.h>
#include <stdlib.h>

// Function to create a magic square
void magic_square(int **arr, int n) {
    int row = 0, col = n / 2;  // Start position
    int prero = row, precol = col;

    for (int i = 1; i <= n * n; i++) {
        arr[row][col] = i;

        // Calculate the next position
        if (row - 1 >= 0) {
            row--;
        } else {
            row = n - 1;
        }

        if (col + 1 < n) {
            col++;
        } else {
            col = 0;
        }

        // If the calculated position is already filled
        if (arr[row][col] != 0) {
            row = prero + 1;
            col = precol;
        }

        prero = row;
        precol = col;
    }

    // Print the magic square
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the size of the magic square (odd number): ");
    scanf("%d", &n);

    if (n <= 0 || n % 2 == 0) {  // Check for positive odd number
        printf("Error: Please enter a positive odd number.\n");
    } else {
        // Dynamically allocate memory for a 2D array using calloc
        int **arr = (int **)calloc(n, sizeof(int *));
        for (int i = 0; i < n; i++) {
            arr[i] = (int *)calloc(n, sizeof(int));
        }

        // Generate the magic square
        magic_square(arr, n);

        // Free the dynamically allocated memory
        for (int i = 0; i < n; i++) {
            free(arr[i]);
        }
        free(arr);
    }

    return 0;
}
