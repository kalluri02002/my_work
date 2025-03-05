#include<stdio.h>
#include <string.h>
int strchar2(char str2[],char ch);
int strcmp2(char str[],char str2[]);
int strchar2(char str2[],char ch){
    int k=strlen(str2);
    for(int i=0;i<k;i++){
        if(str2[i]==ch){
            return i;
        }
    }
    return -1;
}
int strcmp2(char str[],char str2[]){
    int n=strlen(str);
    int m=strlen(str2);
    if(n !=m){
        return 1;
    }
    int i=0;
    while(i<n){
        if(str[i]!=str2[i]){
            return 1;
        }
        i++;
    }
    return  0;
}
int main(){
    char str1[20],str2[20];
    printf("Enter the first string:");
    scanf("%19[^\n]",str1);
    printf("Enter the second string:");
    getchar();// Consume the leftover newline character
    scanf("%19[^\n]",str2);
    if(strcmp2(str1,str2)){
        printf("The strings are not equal.\n");

    }
    else{
        printf("both are same\n");
    }
    char ch='a';
    if(strchar2(str1,'a')==-1){
        printf("no carcter fund\n");

    }
    else{
        printf("found\n");
    }
    



}