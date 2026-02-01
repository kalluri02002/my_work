#include<stdio.h>
int main(){
    FILE *afile;
    char ch;
    afile=fopen("text.txt","r");
    if(afile==NULL){
        printf("file doesnt exits\n");
    }
    else{
        ch=fgetc(afile);
        while(ch !=EOF){
            putchar(ch);
            ch=fgetc(afile);
        }
        printf("\nfile open success fully\n");

    }
    fclose(afile);
}