#include<stdio.h>
int main (){
    int num1,n;
    printf("eneter the gapa and range:\n");
    scanf("%d %d", &num1, &n);
    for(int i=1;i<=num1;i++){
        printf("%d ",i);
        if(i%n==0){
            i=i+n;
        }

    }
}