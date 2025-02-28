#include <stdio.h>

int main() {
    int var = 0x12345678; // Given hexadecimal number
    int extracted = (var >> 16) & 0xFF; // Extract second byte properly

    printf("Extracted value: 0x%X (Decimal: %d)\n", extracted, extracted);

    return 0;
}