// Online C compiler to run C program online
//kalluri Naveen
//Date:24/10/2024
#include <stdio.h>

void nrps(char [], int, int);

int main()
{
    
    int k,n;
    scanf("%d",&k);
    scanf("%d",&n);
    char str[k+1];
    //read the input from the user
    for(int i=0;i<k;i++){
        scanf("%c", &str[i]);
        
    }
    str[k]='\0';
    // checking distict characters or not or not;
    for(int i=0;i<k;i++){
        for(int j=i+1;j<k;j++){
            if(str[i]==str[j]){
                printf("Error : Enter distinct characters");
                return 0;
            }
        }
    }
    int shift=0;
    for(int i=0;i<n;i++){
        printf("%c",str[(i+shift)%k]);
        if(i%k==0){
            shift++;
        }
        
    }
    //function call to pass input to the function
    
}