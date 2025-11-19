#include <stdio.h>

int rangeBitwiseAnd(int left, int right) {
    int shift = 0;
    while (left < right) {
        left >>= 1;
        right >>= 1;
        shift++;
    }
    return left << shift;
}

int main() {
    printf("%d\n", rangeBitwiseAnd(5, 7));   // 4
    printf("%d\n", rangeBitwiseAnd(0, 1));   // 0
    printf("%d\n", rangeBitwiseAnd(6, 7));   // 6
}
