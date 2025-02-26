#include<stdio.h>
int main(){
    int n1,n2;
    printf("enter the number :");
    scanf("%d %d",&n1,&n2);
    printf("before the swap %d and %d\n",n1,n2);
    n1=n1^n2;
    n2=n1^n2;
    n1=n1^n2;
    printf("after the swap %d and %d\n",n1,n2);


}