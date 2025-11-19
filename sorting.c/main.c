#include<stdio.h>
#include "main.h"

void pritarry(int arr[],int n);
void pritarry(int arr[],int n){
    printf("priting array elements\n");
    for(int i=0;i<n;i++){
        printf("%d\n",arr[i]);
    }
}

int main(){
    int arr[6]={5,8,0,69,28,26};
    printf("array elements before sorting\n");
    pritarry(arr,6);
    printf("size of array %ld",sizeof(arr));
   //bubble_sort1(arr,sizeof(arr)/4);
  // insertionsort(arr,6);
   //selection_sort(arr,6);
   quick_sort(arr,0,5);
    pritarry(arr,6);
    

}