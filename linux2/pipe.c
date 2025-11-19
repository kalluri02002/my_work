#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
    int pid= fork();
    if(pid==0){
        for(int i=0;i<10;i++){
            if(i %2==0){
                printf("%d\n",i);
              
            }

        }
    }
    else{
        wait(NULL);
         for(int i=0;i<10;i++){
               
                printf("%d\n",i);
                sleep(1);
              
            

        }
        
    }
}