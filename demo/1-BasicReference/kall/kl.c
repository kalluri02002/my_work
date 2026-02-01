#include <stdio.h>
#include<string.h>


int reverse_recursive(char str[], int ind, int len);
int reverse_recursive(char str[], int ind, int len){
    if(ind==len){
        return 0;
        
    }
    char temp=str[ind];
    str[ind]=str[len];
    str[len]=temp;
    reverse_recursive( str,  ++ind, --len);
    
}


int main()
{
    char str[30];
    
    
    //printf("Enter any string : ");
    scanf("%[^\n]", str);
    
    reverse_recursive(str, 0, strlen(str)-1);
    
    
    
    printf("Reversed string is %s\n", str);
}
