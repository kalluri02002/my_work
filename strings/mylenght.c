#include<stdio.h>
int myLength(char * str);
int myLength(char * str)
{
    int count=0;
    while(*str !='\0'){
        str++;
        count++;
    }
    return count;


}
int main(){
    char str[30]="kalluri";
    printf("%d \n",myLength(str));
    printf("%ld",sizeof(str));



}