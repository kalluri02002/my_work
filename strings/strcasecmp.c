#include <stdio.h>

// Function to convert uppercase to lowercase
char toLower(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        return ch + ('a' - 'A');  // Convert uppercase to lowercase
    }
    return ch;
}

// Custom case-insensitive string comparison
int myStrcasecmp(const char *str1, const char *str2) {
    while (*str1 && *str2) {
        char c1 = toLower(*str1);
        char c2 = toLower(*str2);

        if (c1 != c2) {
            return (unsigned char)c1 - (unsigned char)c2; // Return ASCII difference
        }
        str1++;
        str2++;
    }
    return (unsigned char)toLower(*str1) - (unsigned char)toLower(*str2);
}

int main() {
    char str1[] = "Hello";
    char str2[] = "hello";
    char str3[] = "world";

    printf("Comparing '%s' and '%s': %d\n", str1, str2, myStrcasecmp(str1, str2)); // Should return 0
    printf("Comparing '%s' and '%s': %d\n", str1, str3, myStrcasecmp(str1, str3)); // Should return non-zero

    return 0;
}
