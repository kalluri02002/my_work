#include<stdio.h>
int add1(int a, int b);
int add1(int a, int b){
    while(b){
        int carry=a&b;
        a^=b;
        b=carry<<1;
    }
    return a;
}
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    printf("enetr the vallue %d %d \n",a,b);
    a= add1(a,b);
    printf("total sum is %d \n",a);
}