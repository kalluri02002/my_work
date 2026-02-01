#include <stdio.h>
int add(int num1, int num2)
{
    return num1 + num2;
}
int sub(int num1, int num2)
{
    return num1 - num2;
}
int main()
{
    int(*f[])(int,int) ={add, sub};
    printf("%d\n", f[0](10, 4));
    printf("%d\n", f[1](10, 4));
    return 0;
}