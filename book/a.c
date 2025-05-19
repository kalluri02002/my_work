#include <stdio.h>

int main() {
    int num = 10;
    int *ptr = &num;

    printf("%d\n", *ptr); 
    // Print pointer before modification
    
    (*ptr)++; // Moves ptr to next memory location (undefined behavior)
    printf("%d\n", *ptr);
    ++(*ptr); // Moves ptr to next memory location (undefined behavior)
    printf("%d\n", *ptr);
    *(++ptr); // Moves ptr to next memory location (undefined behavior)
    printf("%d\n", *ptr); // Print pointer after modification

  

    *++ptr; // Moves ptr to next memory location (undefined behavior)
    printf("%d\n", *ptr); // Print pointer after modification

    *ptr++; // Moves ptr to next memory location (undefined behavior)
    printf("%d\n", *ptr); // Print pointer after second modification

    return 0;
}
