// #include<stdio.h>
// int main(){
//     int iter;
//     for( iter=1; iter<5; iter++){
//         printf("%d\n",iter);
//     }
//     printf("iter output %d\n",iter);
// }
//Name:Kalluri naveen
//Date:03/09/2024
#include<stdio.h>
int main(){
    int size,element;
    int arr[size];
    for(int i=0;i<size;i++){
        scanf("%d",&arr(i));
    }
    scanf("%d",&element);
    int tr=0;
    for(int j=0;j<size;j++){
       if(element==arr(j)){
           tr=1;
           break;
           
          
           
       }
    }
    if (tr==1){
         printf("Element Found");
        
    }
    else{
        
        printf("not Found");
    }
}