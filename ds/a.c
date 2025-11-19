#include<stdio.h>
union tk {
    int k;
    char tk[4];
};
int main(){
    union tk thope;
    thope.k=1;
    if(thope.tk[0]==1){
        printf(" little enain shyste \n");
    }
    else{
        printf("big enadian sytem \n");
    }

    int num= 0x12345678;
    char * k=(char *)&num;
    if(*k==0x78){
        printf(" liitle enadi  system \n");
    }
    else{
        printf(" big enadian system \n");
    }

}