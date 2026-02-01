#include<stdio.h>
int main(){
    FILE *afile;
    FILE *afile2;
    char ch;
    afile=fopen("text.txt","r");
    afile2=fopen("text2.txt","w");
    if(afile==NULL){
        printf("file doesnt exits\n");
    }
    else{
        ch =getc(afile);
        while(ch !=EOF){
          putc(ch,afile2);
         ch =getc(afile);


        }
        printf("\nfile open success fully\n");

    }
    fclose(afile);
    fclose(afile2);
}