#include<stdio.h>
#include<stdlib.h>
int main(){
    int * arr;
    arr=(int *)calloc(5,sizeof(int));
    printf("printing the calloc before inilizing values \n");
    for(int i=0;i<5;i++){
        printf("%d \n ",arr[i]);
    }
     printf("printing the calloc inilizing values \n");
    for(int i=0;i<5;i++){
        scanf("%d",&arr[i]);
    }
     printf("printing the calloc  after inilizing values \n");
    for(int i=0;i<5;i++){
        printf("%d \n",arr[i]);
    }
    printf("size of array %ld",sizeof(arr)); /// which give only size of it

    arr=realloc(arr,3*sizeof(int));
     printf("printing the realloc  after inilizing values \n");
    for(int i=0;i<5;i++){
        printf("%d \n",arr[i]);
    }
    printf("size of array %ld",sizeof(arr));
        free(arr);
    
}