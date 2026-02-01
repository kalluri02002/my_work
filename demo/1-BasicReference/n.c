#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>

char *my_strtok(char str[], const char delim[]);
char *my_strtok(char str[], const char delim[]){
    static char *temp;
    static int i=0;
    static int j=0;
    if(str !=NULL){
        j=strlen(str);
        temp=str;
    }
    char *ret=&temp[i];
    if(i==j){
        return NULL;
    }
    for( ;temp[i] !='\0'; i++){
        for(int j=0;j<strlen(delim);j++){
            if(temp[i]==delim[j] ){
                temp[i]='\0';
                i++;
               return ret;
               
            }
        }
    }
    return ret;
}

int main()
{
    char str[50], delim[50];
    
    printf("Enter the string  : ");
    scanf("%s", str);
    
    __fpurge(stdout);
 
    printf("Enter the delimeter : ");
    scanf("\n%s", delim);
    __fpurge(stdout);
    
    char *token = my_strtok(str, delim);
    printf("Tokens :\n");
    
    while (token)
    {   
        if(token[0] !='\0'){

            printf("%s\n", token);
            token = my_strtok(NULL, delim);
        }
        else{

        token = my_strtok(NULL, delim);
        }
    }
}