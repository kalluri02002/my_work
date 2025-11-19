#include<stdio.h>
int main(){
    int num,n,rev=0;
    scanf("%d",&num);
    
    while(num){
        int n=num%10;
        num=num/10;
        rev=rev *10+n;
        
        

    }
    printf("revalution %d ",rev);
}