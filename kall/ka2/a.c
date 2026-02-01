#include<stdio.h>
int * swap_byte(int *,int );
int * swap_byte(int * temp,int n){
    for(int i=0;i<n/2;i++){
        char * t=temp[i];
        temp[i]=temp[n-i-1];
        temp[n-i-1]=t;
        
        
    }
    
   
}

int main(){
    int n;
    scanf("%d",&n);
    if(n==2){
        short int temp;
        scanf("%hd",&temp);
         printf("%hhx\n",temp);
        short int k = swap_byte(&temp, n);
        printf("%hhx\n",k);
        
        
    }
    if(n==4){
          int temp;
        scanf("%d",&temp);
        printf("%hx\n",temp);
         int k = swap_byte(&temp, n);
        printf("%hx\n",k);
        
    }
    if(n==8){
         double temp;
        scanf("%lf",&temp);
         printf("%lf\n",temp);
        double k = swap_byte(&temp, n);
        printf("%lf\n",k);
        
    }
}