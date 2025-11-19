#include<stdio.h>
int main(){
    FILE *fptr=fopen("k1.txt","r");
    char ch ;
    while((ch=fgetc(fptr)) !=EOF){
        printf("%c",ch);

    }
    printf("\n");

}