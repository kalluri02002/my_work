#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(int argc,char argv[]){
pid_t pid=fork();
if(pid==0){
        ececvp(arcv,argc+1);

}
else{
        int status;

        while(waitpid(pid,&status,0)==0){

           printf("paent is running");
        }
	if (WIFEXITED(status)) {
            // Check if child terminated normally
            printf("Child exited normally with status: %d\n", WEXITSTATUS(status));
        } else {
            printf("Child terminated abnormally\n");
        }

}

} 

