#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
int main(){
    int fd[2];
    if(pipe(fd)<0){
        printf("filed fialed");
    }
    int pid=fork();
    if(pid>0){
        close(fd[0]);
        char str[]="kalluri naveen";
        write(fd[1],str,strlen(str)+1);
        printf("writing was done long agao\n");
        close(fd[1]);

    }
    else{
        close(fd[1]);
        char str2[100];
        read(fd[0],str2,50);
        printf("reading was doen parent %s ",str2);
        close(fd[0]);

        
    }

    
}