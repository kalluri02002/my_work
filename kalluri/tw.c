#include<stdio.h>
int main(){
    int num;
    
    scanf("%d", &num);
    // array 1 intialiging
    int arr1[num];
    
    for(int i=0 ; i<num; i++){
        scanf("%d", &arr1[i]);
    }
    for(int i=num-1;i>0; i--){
        
        for(int j=0; j<i; j++){
            if(arr1[j]>arr1[j+1]){
                int temp=arr1[j+1];
                arr1[j+1]=arr1[j];
                arr1[j]=temp;
                
            }
        }
    }
    for(int i=0 ; i<num; i++){
        printf("%d", arr1[i]);
    }
}