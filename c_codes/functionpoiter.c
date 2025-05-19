#include<stdio.h>
void kalluri(){
    printf("Hello, I am Kalluri\n");
}
void kall(int a,int b){
    printf("addintion is %d\n",a+b);
  
}
void kall2(int a,int b){
    printf("addintion 2 is %d\n",a+b);
  
}
int main(){
    void (*ptrfun)();
    ptrfun=kalluri;
    (*ptrfun)();
    void (*ptrfun2)(int,int)=kall;
    (*kall)(2,3);
    void (*arrptr[3])()={kalluri,kall,kall2};
    arrptr[0]();
    arrptr[2](3,4);
    arrptr[1](5,6);

    

}