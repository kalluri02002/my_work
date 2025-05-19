#include <stdio.h>
#include <string.h>

void reverseString(char str[], int start, int end) {
    if (start >= end)
        return;

    // Swap characters
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    // Recursive call
    reverseString(str, start + 1, end - 1);
}

int main() {
    char str[100];

    printf("Enter a string: ");
    scanf("%99s", str); // Read input

    reverseString(str, 0, strlen(str) - 1);
    printf("Reversed string: %s\n", str);

    return 0;
}
