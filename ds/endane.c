#include<stdio.h>
int main(){
    int num=0x12345678;
    char *k=(char *)&num;
    if(*k=0x78){
        printf("its little endiam system");
    }
    else{
        printf("it s big endian system");
    }
}