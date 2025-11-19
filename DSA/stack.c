#include<stdio.h>
#include<stdlib.h>
typedef struct stack
{
int capacity;
int top;
int *item;
}Stack_t;
void creat(Stack_t * S,int size){
    S->capacity=size;
    S->top=-1;   
    S->item=(int *)malloc(sizeof(int)*size);
}
void push(Stack_t * S,int data){
    if ( S -> top ==S -> capacity -1 ){
        printf("Stack is full\n");
    }
     ++(S -> top);
 S -> item [ S -> top]=data;
}
void pop(Stack_t * S){
    if ( S -> top == -1 ){
        printf("Stack is empty\n");
    }

 --(S -> top);

}
void display(Stack_t *S) {
    if (S->top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= S->top; i++) {
        printf("%d ", S->item[i]);
    }
    printf("\n");
}
int main(){
    Stack_t S;
//read the size of the stack from the user
creat( &S , 5);
push ( &S , 5);
push ( &S , 5);
push ( &S , 5);
display(&S);
pop(&S);
display(&S);

}