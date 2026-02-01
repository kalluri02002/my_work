#include<stdio.h>
int main(){
    int lines,j,i;
    printf("Enter the number of lines");
    scanf("%d",&lines);
    printf("\n");
    for(j=1;j<=lines;j++){
        for(i=0;i<j;i++){
            printf("* ");
        }
        printf("\n");
    }

}