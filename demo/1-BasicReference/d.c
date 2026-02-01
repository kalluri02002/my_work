#include <stdio.h>

int main() {
    int num = 0;
    while (num == 0){

        if (num++) {
            break; // Unreachable
        } else {
            printf("No\n");
        }
    } // Infinite loop


    return 0;
}