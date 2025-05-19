#include<stdio.h>
#include<string.h>
int strstr1(char *str, char *str2);
int strstr1(char *str, char *str2){
    int n=strlen(str);
    int m=strlen(str2);
    int j=0;
    for(int i=0;i<=n-m;i++){
        if(str[i]==str2[j]){
            int k=i;
           while( str2[j] !='\0' && str[k]==str2[j] && j<m){
            j++;
            k++;
           }
           if(j==m){
            return i;
           }
           else{
            j=0;
           }


        }
    }
   return -1;
}

int mycmp(char *str, char *str2){
    while (*str != '\0' && *str2 != '\0') {
        if (*str == *str2) {
            str++;
            str2++;
        } else {
            break;
        }
    }
    printf("%d is\n ",*str-*str2);
    return (unsigned char)(*str) - (unsigned char)(*str2);
}
int main(){
    typedef struct 
    {
        int k;
        int p;
    } kall;
    kall a;
    a.k=10;
    a.p=20;
    printf("a is %5d and b is %d equll to %d\n",a.k,a.p,a.k+a.p);
    char str[8]="kalluri";
    char str2[8]="kalluri";
    if(mycmp(str,str2)==0){
        printf("str and str2 are equal\n");
    }
    else{
        printf("str and str2 are not equal\n");
    }
    char str3[50]="is is genious so great kalluri";
    char str4[9]="kalluri3";
    if(strstr1(str3,str4)==-1){
        printf("is not in string");
    }
    else{
        printf("is part of sring");

    }


    
}