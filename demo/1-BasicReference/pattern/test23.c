#include<stdio.h>
int main(){
    int star=1,num;
    scanf("%d",&num);
    for(int i=1;i<=num;i++){
        for(int j=1;j<=num-i;j++){
            printf("  ");
        }
        for(int k=1;k<=star;k++){
            printf("* ");
        }
        printf("\n");
        star=star+2;
    }
}