// File1.c
#include <stdio.h>

// Define the global variable
// This global variable is accessible within File1.c only by default.
int globalVar = 10;

void main() {
    printf("Global variable in File1.c: %d\n", globalVar);
}

/*
Example 1: Global variable
- A global variable is accessible within its defining file by default.
- To access it in another file, use the 'extern' keyword.
*/

// File2.c
#include <stdio.h>

// Declare the global variable from File1.c
extern int globalVar;

void someFunction() {
    printf("Accessing globalVar in File2.c: %d\n", globalVar);
}

/*
Example 2: auto (default storage class)
- Local variables use the 'auto' storage class by default.
*/
#include <stdio.h>

void autoExample() {
    auto int num = 5; // 'auto' is optional
    printf("Auto variable: %d\n", num);
}

/*
Example 3: register
- Suggests storing the variable in a CPU register for faster access.
*/
#include <stdio.h>

void registerExample() {
    register int count = 0;
    for (count = 0; count < 5; count++) {
        printf("Register variable: %d\n", count);
    }
}

/*
Example 4: static (local scope)
- Retains its value across multiple function calls.
*/
#include <stdio.h>

void staticExample() {
    static int counter = 0; // Retains its value between calls
    counter++;
    printf("Static variable: %d\n", counter);
}

/*
Example 5: static (global scope)
- Restricts visibility of a global variable to the same file.
*/
#include <stdio.h>

static int globalStaticVar = 20; // Accessible only within this file

void staticGlobalExample() {
    printf("Static global variable: %d\n", globalStaticVar);
}

/*
Example 6: extern
- Used to declare a variable defined in another file.
*/
#include <stdio.h>

extern int globalVar;

void externExample() {
    printf("Extern variable from File1.c: %d\n", globalVar);
}

/*
Compilation:
1. Compile all related files together, e.g., gcc File1.c File2.c -o program
2. Run the program using ./program
*/
