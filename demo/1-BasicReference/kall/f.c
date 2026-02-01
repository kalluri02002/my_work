#include <stdio.h>

// Macro to calculate size of a type
#define SIZEOF(x) ((char *)(&x + 1) - (char *)(&x))

int main() {
    // Declare variables of different types
    int i;
    char c;
    float f;
    double d;
    unsigned int ui;
    long int li;

    // Display sizes using the SIZEOF macro
    printf("Size of int : %ld bytes\n", SIZEOF(i));
    printf("Size of char : %ld bytes\n", SIZEOF(c));
    printf("Size of float : %ld bytes\n", SIZEOF(f));
    printf("Size of double : %ld bytes\n", SIZEOF(d));
    printf("Size of unsigned int : %ld bytes\n", SIZEOF(ui));
    printf("Size of long int : %ld bytes\n", SIZEOF(li));

    return 0;
}
