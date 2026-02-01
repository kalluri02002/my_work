#include <stdio.h>
#include<string.h>

int getword(char str[]);
int getword(char str[]){
    int n=strlen(str);
    char k[n];
    for(int i=0;i<n;i++){
        if(str[i]==' '){
            break;
        }
        else{
            k[i]=str[i];
            
            
        }
        
    }
    strcpy(str,k);
    
    return strlen(k);
}

int main()
{
        int len = 0;
	    char str[100];

		printf("Enter the string : \n");
		scanf(" %[^\n]", str);

		len = getword(str);

        printf("You entered %s and the length is %d\n", str, len);
}