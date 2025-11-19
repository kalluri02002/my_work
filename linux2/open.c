#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include <string.h>

int main(){
    int fd=open("text.txt",O_CREAT | O_WRONLY ,0644);
    char str[]="kalluri naveen";
    write(fd,str,strlen(str)+1);
    int copy =dup(fd);
     char str2[]="i sking of north";
     write(copy,str2,strlen(str)+1);
  
    
     dup2(STDIN_FILENO,fd);
    write(fd,str2,strlen(str)+1);
    close(copy);
     close(fd);


}
