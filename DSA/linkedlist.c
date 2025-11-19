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
void addlast(struct node ** head ,int data){
    struct node* new=(struct node* )malloc(sizeof(struct node));
    new->data=data;
    struct node * last=*head, *temp;
    while(last){
        temp=last;
        last=last->link;
        
    }
    temp->link=new;
    new->link=NULL;


}
struct node * mid(struct node **head){
    struct node *slow = *head;
    struct node * fast=*head;
    while(fast && fast->link){
        slow=slow->link;
        fast=fast->link->link;
    }
    return slow;
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
int count(struct node * head){
    int count=0;
struct node * temp= head;
while(temp){

    count++;
    temp=temp->link;
}
return count;
}
void delete(struct node **head){
    struct node * temp=*head,*nk;
    while(temp){
        nk=temp;
        temp=temp->link;
        free(nk);

    }
    *head=NULL;
    printf("linked list is delated\n");
}
void bubblesort(struct node **head){
    int k=count(*head);
   
    for(int i=1;i<k;i++){
        struct node * temp=*head;
         struct node * temp2=(*head)->link;
        while(temp2){
            if((temp->data)>(temp2->data)){
                int t=temp->data;
                temp->data=temp2->data;
                temp2->data=t;




            }
            temp=temp->link;
            temp2=temp2->link;

            
            
        }

    }
}
void rev(struct node ** head){
    struct node * prev=NULL;
    struct node * current=*head;
    struct node * next;
    while(current){
        next=current->link;
        current->link=prev;

        prev=current;
       
        current=next;





    }
    *head=prev;
}
int main(){
    struct node* head=NULL;
    adddata(&head,5);
      adddata(&head,51);
        adddata(&head,20);
          adddata(&head,25);
          printlist(head);
          addlast(&head,60);
          adddata(&head,252);
           addlast(&head,600);
           adddata(&head,2502);
            printlist(head);
            struct node* midnode=mid(&head);
            printf("mid value s is %d \n",midnode->data);
            int n=count(head);
            printf("number od nodes %d\n",n);
            bubblesort(&head);
            printlist(head);
             int n1=count(head);
            printf("number od nodes %d\n",n1);
            rev(&head);
             printlist(head);
            delete(&head);
             printlist(head);





    


}