#include<stdio.h>
int main(){
    int a,b;
    printf("enter the number a and b : ");
    scanf("%d%d",&a,&b);
    printf(" A and B are %d and %d\n",a,b);
    a=a^b;
    b=a^b;
    a=a^b;
    printf("after  A and B are %d and %d\n",a,b);
}