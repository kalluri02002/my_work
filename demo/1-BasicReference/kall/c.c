#include <stdio.h>
#include <stdlib.h>
//Name:Kalluri Naveen
//date:02/12/2024
void magic_square(int **, int);
void magic_square(int **arr, int n){
    int row=0,col=n/2;
    int prero=row,precol=col;
    
    for(int i=1;i<=n*n;i++){
        arr[row][col]=i;
        if(row-1>=0){
            row--;
        }
        else{
            row=n-1;
        }
        if((col+1)<n){
            col++;
            
        }
        else{
            col=0;
        }
        if(arr[row][col] !=0){
            row=prero+1;
            col=precol;
            
        }
        prero=row;
        precol=col;
        
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d  ",arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    if(n<=0 || n%2==0){
        printf("Error : Please enter only positive values or odd value");
    }
    else{
          int **arr = (int **)calloc(n, sizeof(int *));
        for (int i = 0; i < n; i++) {
            arr[i] = (int *)calloc(n, sizeof(int));
        }
        magic_square(arr,n);
        
    }
    
}