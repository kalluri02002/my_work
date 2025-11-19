#include<stdio.h>
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    while(b){
        int carry=b&a;
        a=a^b;
        b=carry<<1;
        

    }
    printf("addition a %d",a);
}