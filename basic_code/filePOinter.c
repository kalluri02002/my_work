#include<stdio.h>
int kalluri(){
    return 23;
}
void print(){
    printf("Kalluri Naveen\n");
}
int main(){
    // createing file pointer
    int (*function1)();
    void (*funct2)();
    function1 = kalluri;    
    funct2=print;
    funct2();
    printf("my age is %d\n",function1());

}