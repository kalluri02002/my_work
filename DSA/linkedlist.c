#include<stdio.h>
#include<stdlib.h>
 struct node{
    int data;
    struct node* link;
} ;
void adddata(struct node** head ,int data){
    struct node* new=(struct node* )malloc(sizeof(struct node));
    new->data=data;
    
    new->link= *head;
    *head=new;

}
void printlist(struct node* head){
    struct node* temp=head;
    printf("head->");
    while(temp){
        printf("%d->",temp->data);
        temp=temp->link;

    }
    printf("tail\n");

}
int main(){
    struct node* head=NULL;
    adddata(&head,5);
      adddata(&head,51);
        adddata(&head,20);
          adddata(&head,25);
          printlist(head);



    


}