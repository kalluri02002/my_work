#include<stdio.h>
int main(){
    unsigned int num=0xAABBCCDD,rev=0;
   for(int i=0;i<=31;i++)
   {    
        rev=rev<<1;
        rev=(rev|(num &1));
        num>>=1;

    }
    printf("%x",rev);
}