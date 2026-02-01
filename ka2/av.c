#include<stdio.h>
#include<string.h>
int main(int argc, char* argv[]){
    int sum=0;
    if(argc==0){
        printf("enter the valid input\n");
    }
    else{

    
    for(int i=1;i<argc;i++){
        sum +=atoi(argv[i]);


    }
    printf(" here is tour average %d",sum/(argc-1));
  }
}