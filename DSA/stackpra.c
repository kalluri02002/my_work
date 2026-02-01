#include<stdio.h>
#define max 100
typedef struct {
    int arr[max];
    int top;
}stack;
void push(stack * stm,int n){
    if(stm->top==max-1){
        printf("it is full");
    }
    stm->arr[++(stm->top)]=n;
}
void pop(stack * stm){
    if(stm->top==-1){
        printf("it is Empty");
    }
    (stm->top)--;
}
void display(stack * stm){
    for (int i=0;i<=stm->top;i++){
        printf("%d  ",(stm->arr)[i]);
       

    }
     printf("\n");
} 
int main(){
    stack st;
    st.top=-1;
    push(&st,10);
      push(&st,103);
        push(&st,105);
          push(&st,106);
          display(&st);
      pop(&st);
       pop(&st);
        display(&st);




}