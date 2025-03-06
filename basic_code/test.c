#include <stdio.h>

struct BitField {
    unsigned int a : 3;
    unsigned int b : 5;
    unsigned int c : 8;
};

int main() {
    struct BitField test;
    float k;
    printf("Address of test: %p\n", (void*)&test);
    printf("Address of a: %p\n", (void*)test.a);
    printf("Address of b: %p\n", (void*)test.b);
    printf("Address of c: %p\n", (void*)test.c);
    printf("Size of struct: %lu bytes\n", sizeof(test));
    printf("Size of struct: %lu bytes\n", sizeof(k));
    return 0;
}
