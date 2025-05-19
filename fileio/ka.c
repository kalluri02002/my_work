// Online C compiler to run C program online
#include <stdio.h>

int main() {
    // Write C code here
    printf("enter the number \n");
    int a,b;
   scanf("%d%d",&a,&b);
   printf("innter the number before %d %d",a,b);
   int mul=0;
   while(b){
       if(b&1){
           mul +=a;
           
       }
       b=b>>1;
       a=a<<1;
   }
   printf("the value is %d ",mul);

    return 0;
}