#include<stdio.h>
#include<string.h>
int main(){
    FILE *file=fopen("k1.txt","w+");
    if(file==NULL){
        printf("file not opend\n");
    }
    else{
        printf("file is opnes\n");
    }
    char str[]="kalluri navenn super hero";
    fwrite(str,sizeof(char),strlen(str),file);
    char str1[50];
    fread(str1,sizeof(char),50,file);
    printf("%s\n",str);
    fclose(file);

}