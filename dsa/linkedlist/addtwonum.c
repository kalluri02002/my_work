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

// Function to add two numbers represented by linked lists
struct Node* addTwoNumbers(struct Node* l1, struct Node* l2) {
    struct Node* dummyHead = createNode(0);  // Dummy node to start the result list
    struct Node* current = dummyHead;  // Pointer to construct the new list
    int carry = 0;

    // Traverse both lists
    while (l1 != NULL || l2 != NULL) {
        int x = (l1 != NULL) ? l1->data : 0;  // Get l1 data, 0 if l1 is NULL
        int y = (l2 != NULL) ? l2->data : 0;  // Get l2 data, 0 if l2 is NULL
        int sum = carry + x + y;  // Sum current digits and carry

        carry = sum / 10;  // Calculate new carry
        current->next = createNode(sum % 10);  // Set node data to sum's last digit
        current = current->next;  // Move to next position in result list

        // Move to next nodes in input lists if available
        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;
    }

    // If there's any remaining carry, add a new node
    if (carry > 0) {
        current->next = createNode(carry);
    }

    // Return the next node of dummyHead, as it's a placeholder
    return dummyHead->next;
}

// Helper function to print the list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    // Creating first list: 2 -> 4 -> 3 (represents the number 342)
    struct Node* l1 = createNode(2);
    l1->next = createNode(4);
    l1->next->next = createNode(3);

    // Creating second list: 5 -> 6 -> 4 (represents the number 465)
    struct Node* l2 = createNode(5);
    l2->next = createNode(6);
    l2->next->next = createNode(4);

    struct Node* result = addTwoNumbers(l1, l2);
    printf("Sum List: ");
    printList(result);  // Should output: 7 -> 0 -> 8 -> NULL

    return 0;
}
