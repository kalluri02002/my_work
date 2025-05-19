#include<stdio.h>
#define setbit(num,n)(num |1<<n)
#define swap(a,b)\
   int temp=a;\
   a=b;\
   b=temp;



int main(){
    int num2;
    scanf("%d",&num2);
    printf("the number is %d\n",num2);
    printf("the number is %d\n",setbit(num2,2));
    int a=10,b=15;
    printf("%d%d is \n",a,b);
    swap(a,b);
    printf("%d %d\n",a,b);


}