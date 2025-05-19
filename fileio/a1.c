#include<stdio.h>
int main(){
    FILE *file=fopen("kall.txt","w+");
    if(file==NULL){
        printf("file opening failed");
    }
    else{
        printf("file opened successfully \n");
    }
   
    char str[]="kalluri navenn is a king of kings";
    fprintf(file,"%s\n",str);
    //getchar();
    fseek(file,0,SEEK_SET);
    char k=fgetc(file);
    printf("%c \n",k);
    fseek(file,6,SEEK_SET);
    k=fgetc(file);
    printf("%c \n",k);
    fseek(file,0,SEEK_SET);
    while((k=getc(file) )!=EOF){
        printf("%c",k);
    }
    fclose(file);
}