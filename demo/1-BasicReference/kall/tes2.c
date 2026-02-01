#include<stdio.h>
int main() {
    int num1, num2, num3, mid;
    scanf("%d%d%d",&num1, &num2, &num3);
    if((num2>=num1 && num2<=num3)){
        printf("Middle number is %d",num2);
    }
    else if (num2>=num1 && num3<=num1){
        printf("middle number is %d",num1);
    }
    else{
        printf("middle number is %d", num3);
    }
}