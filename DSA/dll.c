#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
}dlist;
void addele(dlist **head,dlist ** tail,int data){
    dlist * new=(dlist *)malloc(sizeof(dlist));
    if(new==NULL){
        printf("Memory not allocated\n");
        return ;
    }
    new->data=data;
    new->next=NULL;
    new->prev=NULL;
    if(*head ==NULL && *tail ==NULL){
        *head=new;
        *tail=new;

    }
    else{
        new->next=*head;
        (*head)->prev=new;


        *head=new;
    }

}
void addlast(dlist **head,dlist ** tail,int data){
    dlist * new=(dlist *)malloc(sizeof(dlist));
    new->data=data;
    new->next=NULL;
    new->prev=NULL;
    if(*head ==NULL && *tail ==NULL){
        *head=new;
        *tail=new;
        return;
    }
    (*tail)->next=new;
    new->prev=*tail;
    *tail=new;


    
}
void printfkl(dlist *head,dlist * tail){
    printf("head ->");
    dlist * temp=head;
    while(temp!=NULL){
        printf("<-%d->",temp->data);
        temp=temp->next;
    }
     printf("<-tail\n");
}
int main(){
    dlist *head=NULL;
    dlist *tail=NULL;
    addele(&head,&tail,10);
     addele(&head,&tail,30);
      addele(&head,&tail,40);
       addele(&head,&tail,70);
        addele(&head,&tail,60);
        printfkl(head,tail);
        addlast(&head,&tail,8);
         addlast(&head,&tail,25);
           printfkl(head,tail);


}