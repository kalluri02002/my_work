#include<stdio.h>
int main(){
    int n,k=1;
    scanf("%d",&n);

    for(int i=n;i>0; i--){
        
        for(int j=1;j<=i;j++){
            if(i==n || j==1|| j==i ){
                printf("%d ",k);
                k++;
            }
            else{
                printf("  ");
            }
           
        }
        printf("\n");
    }
   
}