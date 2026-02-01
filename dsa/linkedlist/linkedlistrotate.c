#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Helper function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to rotate the list to the right by k places
struct Node* rotateRight(struct Node* head, int k) {
    if (head == NULL || head->next == NULL || k == 0) {
        return head;  // No rotation needed for empty list, single node, or k=0
    }

    // Step 1: Compute the length of the list and make it circular
    struct Node* temp = head;
    int len = 1;
    while (temp->next != NULL) {
        temp = temp->next;
        len++;
    }
    temp->next = head;  // Make the list circular

    // Step 2: Find the new end of the list after rotation
    k = k % len;  // Handle k greater than the length of the list
    int stepsToNewHead = len - k;

    struct Node* newEnd = head;
    for (int i = 1; i < stepsToNewHead; i++) {
        newEnd = newEnd->next;
    }

    // Step 3: Break the circular link to form the new rotated list
    struct Node* newHead = newEnd->next;
    newEnd->next = NULL;

    return newHead;
}

// Helper function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    // Creating the list 1 -> 2 -> 3 -> 4 -> 5
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    int k = 2;
    printf("Original List: ");
    printList(head);

    head = rotateRight(head, k);
    printf("Rotated List by %d positions: ", k);
    printList(head);

    return 0;
}
