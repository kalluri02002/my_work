#include<stdio.h>
void productsum(int *num1,int *num2);

int main(){
    int num1,num2;
    int *product,*sum;
    printf("entet the values");
    scanf("%d %d",&num1,&num2);
    productsum(&num1,&num2);
    printf("product : %d %d",num1,num2);


}
void productsum(int *num1,int *num2){
    int sum=*num1+*num2;
    int product=(*num1)*(*num2);
    *num1=sum;
    *num2=product;
}