#include<stdio.h>
#include <stdarg.h>
int sum(int count,...);
int main(){
    int sum1=(2,20,30);
    printf("The Sum %d\n",sum1);
    
}
int sum(int count,...){
    int res=0;
    va_list Ap;
    va_start(Ap,count);
    for(int i=0;i<count;i++){
        res=res+va_arg(Ap, int);
    }
    va_end(Ap);
    return res;
    
    
}