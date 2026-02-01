#include<stdio.h>
#include <stdlib.h>
int main(){
    void * str=(void *)malloc(8*sizeof(char));
    int i=1;
    int num,ch;//taking inputs
    int char1_n=0,char2_n=0,double_int=0;
    int short_i=0,float_in=0,integer_int=0;

    while(i){
        printf("1 . add element\n");
        printf("2 . display\n");
        printf("3 . romove \n");
        printf("4 . exit \n");
        //printf("1 . char \n");
        scanf("%d",&num);
        switch (num)
        {
        case 1:
            /* code */
            printf("1 . char \n");
            printf("2 . short \n");
            printf("3 . int  \n");
            printf("4 . flaot \n");
            printf("5 . double \n");
            scanf("select the the options\n");
            scanf("%d",&ch);
            switch (ch)
            {
            case 1:
                if(char1_n==0){

                    if(double_int==0 && char1_n==0){
                        printf("enter the character");
                        scanf(" %c",(char *)str);
                        char1_n=1;

                    }
                    else{

                    printf("it already full\n");
                    }
                }
                    else{

                    if(double_int==0 && char1_n==1 && char2_n==0){
                        printf("enter the character");
                        scanf(" %c",(char *)str+1);
                        char2_n=1;

                    }
                    else{
        
                    printf("it already full\n");
                    }
                }
                break;
            case 2:
                /* code */
                if(double_int==0 && short_i==0){
                    printf("enter the short ");
                    scanf("%hd",(short *)str);
                    short_i=1;

                }
                else{

                printf("it already full\n");
                }
                break;
            
            case 3:
                if(double_int==0 && integer_int==0){
                    printf("enter the int ");
                    scanf("%d",(int *)str);
                    integer_int=1;

                }
                else{

                printf("it already full\n");
                }
                /* code */
                break;
            
            case 4:
               if(double_int==0 && float_in==0){
                    printf("enter the flaot value ");
                    scanf("%f",(float *)str);
                    float_in=1;

                }
                else{

                printf("it already full\n");
                }
                /* code */
                break;
            
            case 5:
              if(double_int==0 && integer_int==0 && float_in==0 && char1_n==0 && short_i==0 && char2_n==0){
                    printf("enter the double value ");
                    scanf("%lf",(double *)str);
                    double_int=1;

                }
                else{

                printf("it already full\n");
                }
                /* code */
                break;
            
            
            default:
                printf("please enter the correct choice\n");
                break;
            }
            break;
        case 2:
           // int count=1;
             if(char1_n){
                printf("char . %c   \n",*(char *)str);
                

             }
             if(char2_n){
                printf("char2 %c   \n", (*(char *)str+1));
                

             }
             if(short_i){
                printf("short. %hd   ",*(short *)str);
                

             }
             if(integer_int){
                printf("int . %d   ", (*(int *)str));
                

             }
             if(float_in){
                printf("float %f   ", *(float *)str);
                

             }
             if(double_int){
                printf("double  %lf   ", *(double *)str);
                

             }
             
            break;
        case 3:
             printf("1 enter for char_1 and double \n");
             printf("2 for char_2 \n");
             printf("3 for short  \n");
             printf("4 for in int and flaot \n");
            int no;
            scanf("%d",&no);
            switch (no)
            {
            case 1:
                char1_n=0;
                double_int=0;
                break;
            case 2:
               char2_n=0;
               break;
            case 3:
              short_i=0;
               break;
            case 4:
               float_in=0;
               integer_int=0;
               break;
            default:
                break;
            }
            printf("deleted done \n");
            break;
        case 4:
         i=0;
         printf("program terminated \n");
            break;
        default:
            printf("enter the valid number \n");
            
            break;
        }
    }
}