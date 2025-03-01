// Online C compiler to run C program online
#include <stdio.h>

int main() {
    // Write C code here
    printf("Try programiz.pro\n");
    int n=10;
    int *ptr=&n;
    int **ptr2=&ptr;
    
    

    printf("%d vallue pointer %p  and %lu",*ptr,*ptr2,sizeof(*ptr2));
    

    return 0;
}