#include<stdio.h>
#include<string.h>
int main(){
    char str[30];
    scanf("%29[^\n]",str);
    printf("%s\n",str);
    char * str2=strtok(str,"/");
    char * stack[3000][100];
    int  top =-1;
    int push(char * str3){
        if(top==2999){
            printf("stack is full\n");
        }
        
        strcpy(stack[++top],str3);
    }
    
    void display() {
    printf("\nStack contents:\n");
    for (int i = 0; i <= top; i++) {
        if(top-1==i){
            printf("%s", stack[i]);
        }
        else{
         printf("%s/", stack[i]);
        }
        
    }
}   
    void pop (){
        if(top==-1){
            printf(" no eleiment");
        }
        printf("Popped: %s\n", stack[top]);
        top--;
    }
    while(str2){
        
       if(strcmp(str2, "..") == 0){
        pop();
       }
       else if(strcmp(str2, ".") == 0){
        continue;
       }
       else{
        
        printf("%s ",str2);
        push(str2);
        
      
       } 
       str2=strtok(NULL,"/");

    }
    
    display();
   
   
   
}