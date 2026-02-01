// #include<stdio.h>
// int main(){
//     int arr[5]={10,20,30,40,50};
//     printf("first number %d\n",arr[0]);
//     printf("second number %d\n",arr[1]);
//     printf("last number %d\n",arr[4]);
//     arr[2]=90;
//     printf("third number %d\n",arr[2]);
// // }
// #include<stdio.h>
// int main(){
//     int arr[5];
//     printf(" enter five  vallue");
//     printf("\n");
//     for(int i=0;i<5;i++){
//         printf(" enter a vallue");
//         scanf("%d", &arr[i]);
        
//     }

//     for(int i=0;i<5;i++){
//         printf("%d\n",arr[i]);
       
        
//     }
// }
#include<stdio.h>
int main(){
    int size;
    printf("Enter the size of array ");
    scanf("%d", &size);
    int arr[size];
    for(int i=0;i<size;i++){
        printf("enter the vallue ");
        scanf("%d", &arr[i]);
        
    }
    for(int i=0;i<size;i++){
        printf("enter the vallue is ");
        printf("%d\n", arr[i]);
        
    }
    
    
}