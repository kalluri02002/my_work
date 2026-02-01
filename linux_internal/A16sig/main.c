#include<stdio.h>
#include<unistd.h>
#include<signal.h>
void handler(int signum){
	for(int i=0;i<10;i++){
		printf(" signa is %d\n",signum);
		sleep(1);
	}
}
int main()


{       printf(" pid of main %d\n",getpid());
	struct sigaction new_act;
	new_act.sa_handler=handler;
	new_act.sa_flags=0;
	sigemptyset(&new_act.sa_mask);
	sigaddset(&new_act.sa_mask,SIGINT);
	sigaddset(&new_act.sa_mask,SIGTSTP);
	sigaddset(&new_act.sa_mask,SIGQUIT);
         sigaction(SIGQUIT,&new_act,NULL);
	sigaction(SIGINT,&new_act,NULL);
         sigaction(SIGTSTP,&new_act,NULL);
	 while(1);
	 return 0;

}

