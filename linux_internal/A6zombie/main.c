#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(){
	// fork for child 
pid_t pid=fork();
if(pid==0){
	printf("child starts\n");
	sleep(5);// has 5 sec delay
	printf("chaild stops\n");

}
else{
	int status;
	// status for how it exted and waitpid is used for one pid and WHOHANG is for run in background
	while(waitpid(pid,&status,WNOHANG)==0){
              sleep(1);	
	   printf("paent is running\n");
	}
          if (WIFEXITED(status)) {  
            // Check if child terminated normally
            printf("Child PID %d exited normally with status: %d\n",pid, WEXITSTATUS(status));
        } else {
            printf("Child PID %d terminated abnormally\n",pid);
        }
}

}

