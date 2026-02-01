#include<stdio.h>
int main(){
    int num=0x12345678;
    char c=num;
    if(c==0x78){
        printf("it is little endian \n");
    }
    else{
        printf("it is big endian\n");
    }
}