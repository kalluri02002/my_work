//Name: Kalluri Naveen
//Date:06/09/2024
//disc: finding meaian
#include<stdio.h>
int main (){
    // array size s
    int num1,num2;
    scanf("%d", &num1);
    scanf("%d", &num2);
    // array 1 intialiging
    int arr1[num1];
    int arr2[num2];
    for(int i=0 ; i<num1; i++){
        scanf("%d", &arr1[i]);
    }
    // array 2 intialiging
    for(int i=0 ; i<num2; i++){
        scanf("%d", &arr2[i]);
    }
    for(int i=num1-1;i>0; i--){
        
        for(int j=0; j<i; j++){
            if(arr1[j]>arr1[j+1]){
                int temp=arr1[j+1];
                arr1[j+1]=arr1[j];
                arr1[j]=temp;
                
            }
        }
    }
      for(int i=num2-1;i>0; i--){
        
        for(int j=0; j<i; j++){
            if(arr2[j]>arr2[j+1]){
                 int temp=arr2[j+1];
                arr2[j+1]=arr2[j];
                arr2[j]=temp;
            }
        }
    }

    float me1,me2;
      for(int i=0 ; i<num1; i++){
        printf("%d ", arr1[i]);
    }
    if(num1%2==0){
        me1=arr1[num1/2]+arr1[(num1/2) -1];
        me1=me1/2;
    }
    else{
        me1=arr1[num1/2];
    }
    if(num2%2==0){
        me2=arr2[num2/2]+arr2[(num2/2) -1];
        me2=me2/2;
    }
    else{
        me2=arr2[num2/2];
    }
    float kall=me1+me2;
    printf("Median of array1 : %g\n", me1);
    printf("Median of array2 : %g\n", me2);
    printf("Median of both arrays : %g", kall/2);
}