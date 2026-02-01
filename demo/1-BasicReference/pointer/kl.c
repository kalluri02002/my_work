#include<stdio.h>
int main(){
    int num1,num2;
    char simbaol;
    int output;
    scanf("%d %c %d",&num1,&simbaol,&num2);
    printf("%d %d %c \n", num1, num2,simbaol);
    
    switch(simbaol){
        case '+':
          
                output=num1+num2;
                printf("The Result is : %d",output);
                break;
               
              
          
        case '-':
          {
                output=num1-num2;
                printf("The Result is : %d",output);
                break;
          }
        case 'X':
          {
                output=num1*num2;
                printf("The Result is : %d",output);
                break;
          }
        case '/':
          {
                output=num1/num2;
                printf("The Result is : %d",output);
                break;
          }
          default:
              {
                  printf("Invalid Operator");
              }
    }
    
    
}