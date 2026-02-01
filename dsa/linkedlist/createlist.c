#include<stdio.h>
#include<stdlib.h>
    struct Node{
        int value;
        struct Node *next;
    
    };
struct Node * createNode(int k){
    struct Node * newNode=(struct Node *)malloc(sizeof(struct Node *));
    newNode->value=k;
    return newNode;
}
void addNodebegining(struct Node ** head,int key){
    struct Node * temp=createNode(key);
    temp->next=*head;
    *head=temp;


}
void triverselist(struct Node ** head){
    struct Node * temp=*head;
    while(temp != NULL){
        printf("%d ->",temp->value);
        temp=temp->next;
    }
}
int main(){
    struct Node * head=NULL;
   addNodebegining(&head,1);
   addNodebegining(&head,2);
   addNodebegining(&head,3);
   triverselist(&head);



}
