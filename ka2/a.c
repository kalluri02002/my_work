#include<stdio.h>
#include<string.h>
void strcat1(char *str1,char *str2);
void strcat1(char *str1,char *str2){
    int n=strlen(str1);
    int m=strlen(str2);
    for(int i=0;i<m;i++){
        str1[n+i]=str2[i];
    }
    str1[n+m+1]='\0';

}
int main(){
    char str3[50]="kalluri ";
    char str4[10]="Naveen";
    printf("bedore  %s\n",str3);
    strcat1(str3,str4);
    printf("after the cat %s\n",str3);



    


}