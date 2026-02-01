/*
Name:Kalluri Naveen;
date:06/09/2024
dis:sieve of eartosthenes
*/
#include<stdio.h>
int main(){
    int num;
    scanf("%d", &num);
    
    if(num<0){
        printf("Please enter a positive number which is > 1");
        
    }
    else{
        printf("ok");
        int arr[num-1];
        
        for(int i=0;i<=num-2;i++){
            arr[i]=i+2;
        }
        for(int i=0;i<=num-2;i++){
           printf("%d ", arr[i]); 
        }
        int thu=0,chu=1;
        for (int k=2;k*k<=num;k++){
            printf("ok \n");
             int kl=chu*k;
            
             for(int j=kl+thu; j<=num-2; j=k+j){
                arr[j]=0;
                  
             }
             chu=k;
             thu++;
        }
        printf("The primes less than or equal to %d are : ", num);
        for(int i=0;i<=num-2;i++){
            if(arr[i]==0){
                continue;
            }
            else{
                printf(" %d,", arr[i]);
            }
        }
        
        
    }
}