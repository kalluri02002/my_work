#include<stdio.h>

int main(){
    int a,b;
    printf("enter the a and b");
    scanf("%d%d",&a,&b);// no spaces used in the scanf
    printf("%d is a and %d is b\n",a,b);
    a=a^b;
    b=a^b;
    a=a^b;
    printf("%d is a and %d is b\n",a,b);
    int k;
    printf("enetr the number : ");
    scanf("%d",&k);
    printf("\n integer bists : ");
    for(int i=31;i>=0;i--){
        printf("%d",(k>>i)&1);
        if((i)%4==0){
            printf(" ");
        }
    }
    printf("\n");
}