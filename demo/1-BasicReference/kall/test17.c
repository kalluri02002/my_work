#include<stdio.h>
int main(){
    int num1,num2;
    printf(" enter the num1 and two ");
    scanf("%d%d",&num1, &num2);
    int var=num1;
    for(int i=0;i<2;i++){
    switch (var)
    {
 
    
    case 1:
        printf("one ");
        break;
    case 2:
        printf("two ");
        break;
    case 3:
        printf(" three ");
        break;
    case 4:
        printf("four ");
        break;
   
    case 5:
        printf("five " );
        break;
    case 6:
        printf("six ");
        break;
    case 7:
        printf("seven ");
        break;
    case 8:
        printf("eight ");
        break;
   
    default:
        printf("nine ");
    }
    var=num2;

    }
    
    if(num1%2==0){
        printf(" even");

    }
    else{
        printf(" odd");
    }
    if(num2%2==0){
        printf(" even \n");

    }
    else{
        printf(" odd \n");
    }
    
}