#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int a=0;
    int b=1;
    int c=0;
    printf("febunachi series upto %d \n",n);
    while(a<n){
        printf("%d ",a);
        a=b+c;
        b=c;
        c=a;
    }
}