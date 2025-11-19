#include<stdio.h>
#include<fcntl.h>
#include <unistd.h> 
#include<stdlib.h> 
int main(){
    int fd=open("super.txt",O_WRONLY | O_CREAT);
    int k=dup(1);
    dup2(fd,1);
    printf("Hello World\n");
    fflush(stdout);
    dup2(k,1);
    printf("Hello World\n");
    printf("printing is donw\n");
}