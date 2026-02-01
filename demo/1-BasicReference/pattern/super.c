#include<stdio.h>
int main(){
    int n;
    printf("eneter the number");
    scanf("%d", &n);
    int arr[n];
    printf("enter the umber in array: ");
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
   
    for(int i=0;i<n;i++){
        int k=arr[i];
        for(int j=i+1;j<n;j++){
            if(k==arr[j]){
                printf("%d ",k);
                i=n;
                break;
                
            }
        }
       
            
        
    }


}