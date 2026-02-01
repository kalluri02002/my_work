#include<stdio.h>
#include<string.h>
int palendrome(char *str);
int palendrome(char *str){
    int n=strlen(str);
    int i=0;
    int j=n-1;
    while(i<j){
        if(str[i]==str[j]){
            i++;
            j--;
        }
        else{
            return 1;
        }

    }
    return 0;

}
int main(){
    char str1[]="kalluri";
    char str2[]="abba";
    if(palendrome(str1)==0){
        printf("%s is palendrom\n",str1);
    }
    else{
        printf("%s is not palenrome\n",str1);
    }
    if(palendrome(str2)==0){
        printf("%s is palendrom\n",str2);
    }
    else{
        printf("%s is not palenrome\n",str2);
    }


}