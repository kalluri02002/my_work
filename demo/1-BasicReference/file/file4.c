#include<stdio.h>
int main(){
    FILE *afile;
    char ch='a';
    int num=12;
    float k=1.5;
    afile=fopen("text4.txt","w+");
    if(afile==NULL){
        printf("file doesnt exits\n");
    }
    else{
        fprintf(afile,"%d %c %f",num,ch,k);
        

    }
    fclose(afile);
}