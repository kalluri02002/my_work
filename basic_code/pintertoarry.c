#include <stdio.h>

int main() {
    int a = 10, b = 20, c = 30;
    
    // Array of Pointers
    int *arr_of_ptrs[3] = {&a, &b, &c};
    
    // Pointer to an Array
    int arr[3] = {1, 2, 3};
    int (*ptr_to_arr)[3] = &arr;

    // Incrementing them
    printf("Before Increment: arr_of_ptrs[0] = %d\n", *arr_of_ptrs[0]);
    arr_of_ptrs[0]++; // Moves to next int (4 bytes)

    printf("Before Increment: ptr_to_arr[0][0] = %d\n",( * ptr_to_arr)[0]);
    (*ptr_to_arr)[0]++; // Moves to next array of 3 integers (12 bytes)
     printf("Before Increment: ptr_to_arr[0][0] = %d\n",( * ptr_to_arr)[0]);
    //
    return 0;
}
