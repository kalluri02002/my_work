#include<stdio.h>
#include<stdlib.h>
addElement(struct Node ** head, int num);

    struct Node {
        int data;
        struct Node *next;

    };
    void insertAtBeginning(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}
  
     void addElementok(struct Node** node, int num){
      struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = num;
    new_node->next = *node;
    *node = new_node;

    }
    void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}
int main(){
    struct Node * head=NULL;
    // addElement(&head,1);
    //  addElement(&head,2);
    //   addElement(&head,3);
    addElementok(&head,3);
    addElementok(&head,3);
    addElementok(&head,3);
    printList(head);

}