#include<stdio.h>
int main(){
    int a, b,c;
    //❌ Extra space in scanf("%d ", &a);

//The trailing space (" %d ") causes unexpected behavior because it tells scanf() to expect a non-whitespace character after the number.
    printf("Enter the value of a: ");
    scanf("%d",&a);
    printf("Enter the value of b: ");
    scanf("%d",&b);
    printf("Enter the value of c: ");
    scanf("%d",&c);
    if(a>b){
        if(a>c){
            printf("%d is greater",a);
        }
        else{
            printf("%d is greater",c);
        }

    }
    else{
        if(b>c){
            printf("%d is greater",b);
        }
        else{
            printf("%d is greater",c);
        }

    }
}