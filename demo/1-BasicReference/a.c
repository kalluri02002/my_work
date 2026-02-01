#include <stdio.h>

int countSetBits(unsigned int num) {
    int count = 0;
    while (num) {
        count += num & 1;
        num =num>> 1;
    }
    return count;
}

int main() {
    unsigned int num = 0xA5;  // Example value
    int setBits = countSetBits(num);
    printf("Number of set bits in %d is %d\n", num, setBits);
    return 0;}