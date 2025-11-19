#include<stdio.h>
int main(){
    int num[100];
    int freq[100];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&num[i]);
        freq[i]=-1;
    }
    for(int i=0;i<n;i++){
        int count=1;
        for(int j=i+1;j<n;j++){
            if(num[i]==num[j]){
                count++;
                freq[j]=0;

            }
        }
        if(freq[i] !=0){
            freq[i]=count;

        }
    }
    for(int i =0;i<n;i++){
        if(freq[i] !=0){

        
        printf(" %d %d\n",num[i],freq[i]);
        }
    }
}