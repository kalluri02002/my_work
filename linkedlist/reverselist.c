#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to reverse the linked list
struct Node* reverseList(struct Node* head) {
    struct Node *prev = NULL, *curr = head, *next = NULL;

    while (curr != NULL) {
        next = curr->next;  // Store next node
        curr->next = prev;  // Reverse the link
        prev = curr;        // Move prev to current node
        curr = next;        // Move to next node
    }
    return prev;  // New head of the reversed list
}

// Function to insert a new node at the beginning
void insert(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Creating linked list: 10 -> 20 -> 30 -> 40 -> NULL
    insert(&head, 40);
    insert(&head, 30);
    insert(&head, 20);
    insert(&head, 10);

    printf("Original list: ");
    printList(head);

    head = reverseList(head);

    printf("Reversed list: ");
    printList(head);

    return 0;
}

// #include <stdio.h>
// #include <stdlib.h>

// struct Node {
//     int data;
//     struct Node* next;
// };

// // Recursive function to reverse the linked list
// struct Node* reverseListRecursive(struct Node* head) {
//     if (head == NULL || head->next == NULL) {
//         return head; // Base case: last node becomes the new head
//     }

//     struct Node* newHead = reverseListRecursive(head->next);
//     head->next->next = head; // Reverse the link
//     head->next = NULL; // Set old head's next to NULL

//     return newHead;
// }

// // Function to insert a node
// void insert(struct Node** head, int data) {
//     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//     newNode->data = data;
//     newNode->next = *head;
//     *head = newNode;
// }

// // Function to print the list
// void printList(struct Node* head) {
//     while (head != NULL) {
//         printf("%d -> ", head->data);
//         head = head->next;
//     }
//     printf("NULL\n");
// }

// int main() {
//     struct Node* head = NULL;

//     insert(&head, 40);
//     insert(&head, 30);
//     insert(&head, 20);
//     insert(&head, 10);

//     printf("Original list: ");
//     printList(head);

//     head = reverseListRecursive(head);

//     printf("Reversed list: ");
//     printList(head);

//     return 0;
// }
