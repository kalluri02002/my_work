#include<stdio.h>
#include<time.h>
#include<stdint.h>
int  method1(int n){
    int count=0;
    while(n){
        n=n&(n-1);
        count++;
    }
    return count;
}
int main(){
    int num;
    printf("enete the number\n");
    scanf("%d",&num);
    clock_t start=clock();
    printf("enter the number %d \n",method1(num));
     clock_t stop=clock();
    printf("time %d \n",(start-stop));
      clock_t start1=clock();
    printf("enter the number %d \n",__builtin_popcountll(num));
      clock_t stop2=clock();
        printf("time %lf \n", (double)(start1 - stop) / CLOCKS_PER_SEC);

}