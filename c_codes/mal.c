#include<stdio.h>
#include <stdlib.h>
int main(){
    int *ptr;
    ptr=(int *)malloc(sizeof(int)*5);
    for(int i=0;i<5;i++){
        *(ptr+i)=i+1;
    }
    for(int i=0;i<5;i++){
        printf("%d ",*(ptr+i));
    }
    int *ptr2;
    ptr2=(int *)calloc(5,sizeof(int));
    printf("\n size of %ld \n",sizeof(ptr2));
    for(int i=0;i<5;i++){
        printf(" %d",*(ptr2+i));
    }
    for(int i=0;i<5;i++){
       *(ptr2+i)=i+1;
    }
    printf("ok \n");
  
    int *temp=realloc(ptr2,10*sizeof(int));
    printf("ok \n");
    for(int i=0;i<10;i++){
        printf(" %d",*(temp+i));
    }
    free(ptr2);
    free(ptr);
    

}