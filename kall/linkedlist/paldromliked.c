// Function to check if the linked list is a palindrome
int isPalindrome(struct Node* head) {
    // Find the middle and reverse the second half, then compare both halves
    struct Node *slow = head, *fast = head, *prev = NULL, *secondHalf, *midNode = NULL;
    
    if (head != NULL && head->next != NULL) {
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }

        // If the list has an odd number of elements, skip the middle element
        if (fast != NULL) {
            midNode = slow;
            slow = slow->next;
        }
        
        secondHalf = slow;
        prev->next = NULL;  // Cut the list into two halves
        reverseList(&secondHalf);  // Reverse the second half

        // Compare both halves
        int result = compareLists(head, secondHalf);

        // Restore the list
        reverseList(&secondHalf);  // Reverse again
        if (midNode != NULL) {
            prev->next = midNode;
            midNode->next = secondHalf;
        } else {
            prev->next = secondHalf;
        }
        
        return result;
    }
    return 1;
}

// Helper function to compare two lists
int compareLists(struct Node* head1, struct Node* head2) {
    while (head1 && head2) {
        if (head1->data != head2->data) return 0;
        head1 = head1->next;
        head2 = head2->next;
    }
    return (head1 == NULL && head2 == NULL);
}
