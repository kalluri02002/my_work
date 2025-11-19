#include<stdio.h>
#include <fcntl.h>      // for open()
#include <unistd.h> 
#include<stdlib.h> 
int main(){
    int fd=open("kalluri2.txt",O_WRONLY | O_CREAT |O_TRUNC, 0777);
    if (fd == -1) {
        perror("file not opened");   // Use perror for better debugging
        exit(1);
    }
    int stdout2=dup(1);
    dup2(fd,1);
    printf("kalluri naveen\n");
        fflush(stdout);  // write in the file immidiately
    dup2(stdout2, 1);
printf("This statement to be printed on stdout\n");


}