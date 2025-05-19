#include"main.h"
void swap(int * a, int *b){
    int temp=*a;
    *b=*a;
    *a=temp;
}
int partion(int arr[],int low,int high){
    int pivot=arr[high];
    int i=low-1;
    for(int j=low;j<high;j++){
        if(arr[j]<pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return (i+1);
}
void quicksort(int arr[],int low,int high){
    if(low<high){
        int pivot=partion(arr,low,high);
        quicksort(arr,low,pivot-1);
        quicksort(arr,pivot+1,high);

    }
}