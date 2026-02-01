
#include<stdio.h>

int main(){
    int k,m=1;
    scanf("%d",&k);
    for(int i=2;i<=k+1;i++){
        printf("%d ",m);
        m=m*i;
       
    }
}