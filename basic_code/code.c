#include <stdio.h>
int fun() {
    static int a = 2;
    a++;
    return a;
    }
    int main() {
    int result1 = fun();
    int result2 = fun();
    printf("%d\n", result1);
    printf("%d\n", result2);
    //out put static varible has 
    //3
//4 
// In C, the lifetime of a static variable extends throughout the entire execution of the program. 
// This means that once a static variable is initialized, it remains in memory and retains its value until the program terminates,
//  regardless of the scope in which it is defined

    }