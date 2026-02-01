#include<stdio.h>
int main(){
    int num,k,total=0;
    scanf("%d", &num);

    while(num>0){
        k=num%10;
        num=num/10;
        total=total*10+k;
        
    } 
    k=num;
   
    if(num==total){
        printf("The Entered number is an palindrome");
    }
    else{
        printf("The Entered number is not an palindrome");
    }
}