#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};  // Correct array declaration
    int* ptr1 = arr;   // Pointer to the first element
    int* ptr2 = arr + 5;  // Pointer to the 6th element
    
    printf("%ld\n", ptr2 - ptr1);  // Difference in terms of elements
    printf("%ld\n", (char*)ptr2 - (char*)ptr1);  // Difference in terms of bytes

    return 0;
}
