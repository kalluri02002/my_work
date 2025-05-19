#include<stdio.h>
int main(){
    union edian
    {
        int k;
        char str[4];
    };
    union edian ko;
    ko.k=0x12345678;
    if(ko.str[0]==0x78){
        printf("it little endian");

    }
    else{
        printf("it big endian");

    }

    
}