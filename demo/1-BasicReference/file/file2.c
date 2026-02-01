#include<stdio.h>
int main(){
    FILE *afile;
    char ch='A';
    afile=fopen("text2.txt","w");
    if(afile==NULL){
        printf("file doesnt exits\n");
    }
    else{
        putc(ch,afile);
        printf("\nfile open success fully\n");

    }
    fclose(afile);
}