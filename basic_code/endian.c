// Little Endian:
// The least significant byte (LSB) is stored at the lowest memory address.
// Example: 0x12345678 is stored as:
// makefile
// Copy
// Edit
// Address:  | 0x00 | 0x01 | 0x02 | 0x03 |
// Data:     | 0x78 | 0x56 | 0x34 | 0x12 |  
// Big Endian:
// The most significant byte (MSB) is stored at the lowest memory address.
// Example: 0x12345678 is stored as:
// makefile
// Copy
// Edit
// Address:  | 0x00 | 0x01 | 0x02 | 0x03 |
// Data:     | 0x12 | 0x34 | 0x56 | 0x78 |
#include<stdio.h>
int main(){
    int num=0x12345678;
    char *k=&num;
    if(*k==0x12){
        printf("big endiannes \n");
    }
    else{
         printf("little endiannes \n");
    }
}