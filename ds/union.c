#include<stdio.h>
union data{
    int num;
    char k;
};
int main(){
    union data a;
    a.num=1;
    if(a.k==1){
        printf("it little endian system");
    }
    else{
        printf("it big endian system");
    }
    
}