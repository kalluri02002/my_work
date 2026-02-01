// Online C compiler to run C program online
//Name:Kalluri Naveen
//date:30/11/2024
#include<stdio.h>
int generatefeb(int one ,int two, int num );
int generatefeb(int one ,int two, int num){
    if(num>(-one)){
       
       return 0;
    }
       printf("%d ",one);
    generatefeb(two-one , one, num);
    
   
}
int main(){
    int num;
    scanf("%d",&num);
    generatefeb(0,1,num); 
}



