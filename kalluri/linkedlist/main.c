#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Function to insert a node at the beginning
void insertAtBeginning(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to insert a node at the end
void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref; // Set last to the head node
    new_node->data = new_data;
    new_node->next = NULL;
    
    // If the list is empty, make the new node the head
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    
    // Otherwise, traverse to the last node
    while (last->next != NULL) {
        last = last->next;
    }
    
    // Change the next of the last node to the new node
    last->next = new_node;
}

// Function to delete a node by value
void deleteNode(struct Node** head_ref, int key) {
    struct Node* temp = *head_ref;
    struct Node* prev = NULL;

    // If the head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next; // Change head
        free(temp); // Free the old head
        return;
    }

    // Search for the key to be deleted
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If the key was not present in the list
    if (temp == NULL) return;

    // Unlink the node and free the memory
    prev->next = temp->next;
    free(temp);
}

int main() {
    struct Node* head = NULL;

    // Insert some elements at the end
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);

    // Print the current list
    printf("Linked list after inserting at the end:\n");
    printList(head);

    // Insert at the beginning
    insertAtBeginning(&head, 0);

    // Print the updated list
    printf("Linked list after inserting at the beginning:\n");
    printList(head);

    // Delete a node with value 2
    deleteNode(&head, 2);

    // Print the final list
    printf("Linked list after deleting node with value 2:\n");
    printList(head);

    return 0;
}
