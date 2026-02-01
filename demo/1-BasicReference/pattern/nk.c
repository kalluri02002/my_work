#include<stdio.h>
int main(){
    int num,n;
    printf("Enter the num and n");
    scanf("%d %d", &num, &n);
    for(int i=1 ;i<=num; i++){
        printf("%d ",i);
        if(i%n==0){
            i=i+n;
        }
    }
    
}