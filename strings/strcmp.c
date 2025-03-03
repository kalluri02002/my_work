#include<stdio.h>
int my_strcmp(char str[], char str2[]);
int my_strcmp(char str[], char str2[]){
    while(*str && (*str== *str2)){
        str++;
        str2++;
    }
    return *str-*str2;
}

int main(){
    char k[40]="naveeen";
    char k1[40]="naveeen";
    char k2[40]="naveep";
    printf("%d\n",my_strcmp(k,k1));
    printf("%d\n",my_strcmp(k1,k2));
    printf("%d\n",my_strcmp(k2,k1));


}
// kallluri starting strcasecmp
