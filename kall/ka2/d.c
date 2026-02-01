#include <stdio.h>
#include <stdlib.h>

// Function to multiply two matrices
void matrix_multiply(int **A, int r1, int c1, int **B, int r2, int c2, int **R) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            R[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                R[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int r1, c1, r2, c2;

    // Input dimensions for Matrix A
    printf("Enter number of rows for Matrix A: ");
    scanf("%d", &r1);
    printf("Enter number of columns for Matrix A: ");
    scanf("%d", &c1);

    // Allocate memory for Matrix A
    int **A = (int **)malloc(r1 * sizeof(int *));
    for (int i = 0; i < r1; i++) {
        A[i] = (int *)malloc(c1 * sizeof(int));
    }

    // Input elements for Matrix A
    printf("Enter values for %d x %d Matrix A:\n", r1, c1);
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Input dimensions for Matrix B
    printf("Enter number of rows for Matrix B: ");
    scanf("%d", &r2);
    printf("Enter number of columns for Matrix B: ");
    scanf("%d", &c2);

    // Check if multiplication is possible
    if (c1 != r2) {
        printf("Matrix multiplication is not possible\n");
        // Free allocated memory for Matrix A
        for (int i = 0; i < r1; i++) {
            free(A[i]);
        }
        free(A);
        return 0;
    }

    // Allocate memory for Matrix B
    int **B = (int **)malloc(r2 * sizeof(int *));
    for (int i = 0; i < r2; i++) {
        B[i] = (int *)malloc(c2 * sizeof(int));
    }

    // Input elements for Matrix B
    printf("Enter values for %d x %d Matrix B:\n", r2, c2);
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // Allocate memory for Result Matrix R
    int **R = (int **)malloc(r1 * sizeof(int *));
    for (int i = 0; i < r1; i++) {
        R[i] = (int *)malloc(c2 * sizeof(int));
    }

    // Perform matrix multiplication
    matrix_multiply(A, r1, c1, B, r2, c2, R);

    // Output the result
    printf("Product of two matrices:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            printf("%d ", R[i][j]);
        }
        printf("\n");
    }

    // Free allocated memory
    for (int i = 0; i < r1; i++) free(A[i]);
    free(A);
    for (int i = 0; i < r2; i++) free(B[i]);
    free(B);
    for (int i = 0; i < r1; i++) free(R[i]);
    free(R);

    return 0;
}
