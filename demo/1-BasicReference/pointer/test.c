#include<stdio.h>
int main(){
    int date,month,year;
    printf("Please enter the DD-MM-YYYY\n");
    scanf("%d*%c%d*%c%d",&date,&month,&year);
    printf("your month is %d-%d-%d\n",date,month,year);
}