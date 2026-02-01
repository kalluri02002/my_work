#include<stdio.h>
int main(int arg,char * argv[]){
    int i;
    for (i=1;i<arg;i++){
        printf("%s \n",argv[i]);
    }

}
