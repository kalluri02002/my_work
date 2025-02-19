// Online C compiler to run C program online
#include <stdio.h>
#include<string.h>
void strcat1(char * str1,char *str2);
void strcat1(char * str1,char *str2)
{
    int n=strlen(str1);
    int m=strlen(str2);
    for(int i=0;i<m;i++){
        str1[n+i]=str2[i];
    }
    str1[n+m]='\0';
    
    
}
int main() {
   char str[]="naveen";
   char str2[15]="kalluri";
    printf("%s\n",str);
   strcat1(str,str2);
   printf("%s",str);
   
    printf("Try programiz.pro");

    return 0;
}