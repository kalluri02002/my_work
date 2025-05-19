#include <stdio.h>

struct __attribute__((packed)) PackedStruct {
    char a;
    int b;
    char c;
};

struct DefaultStruct {
    char a;
  
    char c;
    int b;// 8 bytes
};
struct DefaultStruct2 {
    char a;
  
   
    int b;
    char c;//12 btes
};

int main() {
    printf("Size of PackedStruct: %lu\n", sizeof(struct PackedStruct));
    printf("Size of DefaultStruct: %lu\n", sizeof(struct DefaultStruct));
    return 0;
}