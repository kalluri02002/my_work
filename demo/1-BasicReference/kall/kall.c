// #include<stdio.h>
// int main(){
//     int num1,num2;
//     char k2;
//     printf("enter the vallue od nums");
//     scanf("%d%d%c",&num1,&num2,&k2);
//     // printf("enter the you like character");
//     // scanf("%c",&k2);
    
//     printf("char %d num1 %d num %d",k2, num1,num2);    
// }
#include<stdio.h>
int main(){
    int digit;
    scanf("%d",&digit);
    if(digit>0)
    {
        if(digit%2==0){

          printf("%d is positive even number",digit);
        }
        else{
          printf("%d is positive odd number",digit);
        }
    }
    else{
        if(digit==0){
            printf("%d is neither odd nor even",digit);
        }
        else if(digit%2==0){

          printf("%d is negative even number",digit);
        }
       
        else{
          printf("%d is negative odd number",digit);
        }

    }

 
    
}
