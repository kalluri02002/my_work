#include <stdio.h>
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
   
    printf("%d %d \n",a,b);
    int ret;
    while(b){
        if(b &1)
         ret +=a;
        a <<=1;
        b >>=1;
        
        
    }
    printf("%d %d",ret,b);
    
}