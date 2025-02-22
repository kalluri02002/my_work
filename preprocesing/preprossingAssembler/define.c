// in this page we are writing the data about # define
# define kall 10
#include<stdio.h>
# define kall2 11
# define add1(a,b) ((a)+(b))
# define MAX(x,y)(((x)>(y))? (x):(y))
# define FORLOOP(i, n)for(int i=0;i<(n);i++)
# define PRINTKALLURI for(int i=0;i<5;i++)\
printf("Kalluri Naveen \n");
//#define FORLOOP(i, n) for (int i = 0; i < (n); i++)
//#define MAX(a, b) ((a) > (b) ? (a) : (b))
# define setbit(num, n)(num| 1<<n)
# define clearbit(num,n)(num&~(1<<n))
#define CLEARBIT(num, n) ((num) & ~(1 << (n)))

int main(){
    printf("%d \n",kall);
    printf("%d \n",kall2);

// here we chacking with functions
    printf("%d \n",add1(25,13));
// now here we checking with tough function whick is max
   printf("%d \n",MAX(100,101));
// more tough one for loop
FORLOOP(i, 5) {  // Correct macro usage
    printf("kalluri %d \n", i);
}
// printing kalluri Naveen 5 times
PRINTKALLURI;
// now we are trying set and clar bit using macros bit
int num=16;// clear the 4 bit
int num2=15; // set 5 bit of 
printf("%d %d\n",num,num2);
printf("%d %d\n",setbit(num,5), CLEARBIT(num2,3));


return 0;


}