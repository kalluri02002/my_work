#include<stdio.h>
#include<string.h>
void remove1(char str[]);
void remove1(char str[]){
    char str2[100];
    int i=0,j=0;
    while(str[j] !='\0'){
        if(str [j] != ' '){
            str2[i++]= str[j];



        }
        j++;
        
    }
    str2[i]='\0';
    strcpy(str,str2);
    
    
}
int main(){
    char  str[30];
    printf("Enter a string: ");
    scanf("%29[^\n]",str);
    printf("You entered: %s\n",str);
    remove1(str);
    printf("You entered2: %s\n",str);

    
}