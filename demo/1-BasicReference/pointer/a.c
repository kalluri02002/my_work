#include <stdio.h>

int third_largest(int [], int);
int third_largest(int arr[], int size){
    int f=0,s=0,t=0;//fisr second third taken as latters;
    for(int i=0;i<size;i++){
        if(arr[i]>f){
            t=s;
            s=f;
            f=arr[i];
        }
        if (arr[i]>s && arr[i]<f){
            t=s;
            s=arr[i];
        }
        if(arr[i] >t && arr[i]<s){
            t=arr[i];
        }
    }
    return t;
    
}

int main()
{
    int size, ret;
    
    //Read size from the user
   printf("Enter the size of the array :");
    scanf("%d", &size);
    
    int arr[size];
    
    //Read elements into the array
    for(int i=0;i<size;i++){
        scanf("%d", &arr[i]);
    }
    
    //funtion call
    ret = third_largest(arr, size);
    
    printf("Third largest element of the array is %d\n", ret);
}