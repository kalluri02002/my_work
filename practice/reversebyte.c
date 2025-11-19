#include<stdio.h>
int main(){
    unsigned int num=0xAABBCCDD;
    printf("before reverse the number %x\n",num);
    num=((num>>24)&0x000000FF)|((num>>8)&0x0000FF00)|((num<<24)&0xFF000000) |((num<<8)&0x00FF0000);
    printf("after reverse the number %x\n",num);
}