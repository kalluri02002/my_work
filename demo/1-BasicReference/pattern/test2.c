//Name:kalluri Naveen
//Date:29/08/2024
//disciption:is prime or not

#include <stdio.h>


int main()
{ 
    int num,j=0;
    scanf("%d",&num);
    if(num<=0){
        printf("Invalid input");
       
    }
    else{
        for(int k=2;k<=num;k++){
            for(int i=2;i<=sqrt(k);i++){
                if(num%i==0){
                    printf("%d is not a prime number", k);
                    j++;
                    break;
                }
            }
            if(j==0){
                printf("%d is a prime number", k);
            }

        }
    }
   
}