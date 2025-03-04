#include<stdio.h>
#include <string.h>
int main(){
    char big[]="kalluri naveenn is good boy is going to running every day";
    char small[]="going";
    int n=strlen(big);
    int m=strlen(small);
    int j,ok=0;

    for(int i=0;i<n;i++){
        if(big[i]==small[0]){
            int j=1;
            while(j<m){
                if(big[i+j]!=small[j]){
                    break;
                }
                j++;
            }
            if(j==m){
                int ok=1;
                printf("strstr\n");
                break;
            }
        }
    }
    if(ok==0){
        printf("it is not part of it");
    }
}
