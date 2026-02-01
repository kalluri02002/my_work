#include <stdio.h>
#include<string.h>

void squeeze(char [], char []);
void squeeze(char *str1, char *str2){
    int j=0;
    int flag=1;
    for(int i=0; i<strlen(str1); i++){
        for(int k=0; k<strlen(str2); k++){
            if(str1[i] ==str2[k]){
                flag=0;
                break;
                
                
            }
            
        }
        if(flag){
            str1[j]=str1[i];
            j++;
        }
        flag=1;
        
    }
    str1[j]='\0';
    
}

int main()
{
    char str1[30], str2[30];
    
    printf("Enter string1:");
   scanf(" %s", str1);
    
   
    printf("Enter string2:");
    scanf("%s", str2);
    
    squeeze(str1, str2);
    
    printf("After squeeze s1 : %s\n", str1);
    
}