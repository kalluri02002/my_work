#include<stdio.h>
#include<string.h>
void strcat2(char dest1[],char source1[]);
int main(){
    char dest[20]="kalluri";
    char source[10]="naveen";
    printf(" str cat is %s \n",dest);
    strcat2(dest,source);
    printf(" after str cat is %s \n",dest);

}
void strcat2(char dest1[],char source1[]){ 
    int n=strlen(source1);
    int m=strlen(dest1);
    for(int i=m;i<n+m;i++){
        dest1[i]=source1[i-m];  
    }
    dest1[n+m]='\0';    

}