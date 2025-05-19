#include<stdio.h>
#include <string.h>
void removed(char str[]);
void rev(char str[]);
void rev(char str[]){
    int n=strlen(str);
    for(int i=0;i<n/2;i++){
        char temp=str[i];
        str[i]=str[n-i-1];
        str[n-i-1]=temp;
    }
}
void removed(char str[]){
    int j=0;
    int hash[256]={0};
    int n=strlen(str);
    char newstr[n+1];
    for(int i=0;i<n;i++){
        if(hash[(unsigned char)str[i]]==0){
            hash[(unsigned char)str[i]]=1;
            newstr[j++]=str[i];

        }
    }
    newstr[j]='\0';
    strcpy(str,newstr);
}
int main(){
    char str[20];
    printf("Enter a string: ");
    scanf("%19[^\n]" ,str);
    printf("before printing %s \n",str);
    removed(str);
    printf("after the remove %s\n",str);
    getchar();
    char str2[20];
    printf("Enter a string: ");
    scanf("%19[^\n]" ,str2);
    printf("before printing %s \n",str2);                     
    rev(str2);


    printf("after the remove %s\n",str2 );

}
