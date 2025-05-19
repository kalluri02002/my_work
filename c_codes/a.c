#include <stdio.h>

unsigned short swapMSBandLSB(unsigned short num) {
    unsigned short msb = (num & 0xF000) >> 12;  // Extract MSB (first 4 bits)
    unsigned short second = (num & 0x0F00);     // Extract second nibble (unchanged)
    unsigned short third = (num & 0x00F0);      // Extract third nibble (unchanged)
    unsigned short lsb = (num & 0x000F) << 12;  // Extract LSB (last 4 bits) and shift to MSB

    return (lsb) | (third) | (second) | (msb);
}

int main() {
    unsigned short num = 0xABCD; // Example input
    printf("Original:  0x%X\n", num);
    printf("Swapped :  0x%X\n", swapMSBandLSB(num));

    return 0;
}
