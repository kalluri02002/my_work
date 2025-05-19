#include <stdio.h>
#define setbit(num,n)(num &~(1<n))

// Function to set n LSBs (set to 1)
int setLSBBits(int num, int n) {
    int mask = (1 << n) - 1;  // Create mask with n bits set
    return num | mask;
}

// Function to clear n LSBs (set to 0)
int clearLSBBits(int num, int n) {
    int mask = ~((1 << n) - 1);  // Create mask with n LSBs cleared
    return num & mask;
}

// Function to get n LSBs (extract them)
int getLSBBits(int num, int n) {
    int mask = (1 << n) - 1;  // Create mask with n bits set
    return num & mask;
}

int main() {
    int num, n;

    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Enter number of bits to modify from LSB: ");
    scanf("%d", &n);
   
    printf("Original number: %d\n", num);
    printf("After setting %d LSBs: %d\n", n, setLSBBits(num, n));
    printf("After clearing %d LSBs: %d\n", n, clearLSBBits(num, n));
    printf("Extracted %d LSBs: %d\n", n, getLSBBits(num, n));
    int num1;
    scanf("%d",&num1);
    printf("%d\n",num1);
    setbit(num1,4);
    printf(  "  %d ",setbit(num1,4));

    return 0;
}
