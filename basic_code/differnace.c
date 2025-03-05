#include <stdio.h>

void calculate(int a, int b, int c, int d) {
    int sum = a + b + c + d;          // Calculate sum
    int difference = a - b - c - d;   // Calculate difference

    printf("Sum of the numbers: %d\n", sum);
    printf("Difference of the numbers: %d\n", difference);
}

int main() {
    int a, b, c, d;

    // Taking input from user
    printf("Enter four integers:\n");
    scanf("%d %d %d %d", &a, &b, &c, &d);

    // Call function to calculate sum and difference
    calculate(a, b, c, d);

    return 0;
}
