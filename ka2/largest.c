#include<stdio.h>
# define laegest(a,b,c)((a>b)?((a>c)?a:c):(b>c)?b:c)
int main(){
    int a=10,b=6,c=7;
    printf("%d\n",laegest(a,b,c));
    int d=10,e=600,f=700;
    printf("%d\n",laegest(d,e,f));

}