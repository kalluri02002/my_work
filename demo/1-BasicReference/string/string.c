#include<stdio.h>
int main(){
    char str[20];
    printf("Enter the strng");
    scanf("%19[^\n]", str);
    printf("%s \n", str);
}