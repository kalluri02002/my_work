#include<stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argc,char * argv[]){
int choice;
printf("1.dup\n");
printf("2.dup2\n");
scanf("%d",&choice);
int fd=open(argv[1],O_WRONLY|O_CREAT,0644);
if(choice==1){

int backup=dup(1);
close(1);
dup(fd);
printf("this fil1.txt space\n");
}
else if(choice==2){
dup2(fd,1);
printf("printing using dup2\n");

}
else {
        printf("enter the proper output\n");
}



}
