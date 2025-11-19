#include<stdio.h>
#include<unistd.h>
int main(){
    char * arges[]={"echo","kalluri naveen",NULL};
    printf("exec vp done\n");
    execvp("echo",arges);
     printf("afte exec vp done\n");



}