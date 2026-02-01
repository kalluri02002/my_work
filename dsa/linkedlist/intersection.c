#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int getLength(struct Node* head) {
    int length = 0;
    while (head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}

struct Node* getIntersectionNode(struct Node* headA, struct Node* headB) {
    int lenA = getLength(headA);
    int lenB = getLength(headB);

    while (lenA > lenB) {
        headA = headA->next;
        lenA--;
    }

    while (lenB > lenA) {
        headB = headB->next;
        lenB--;
    }

    while (headA != NULL && headB != NULL) {
        if (headA == headB) return headA;
        headA = headA->next;
        headB = headB->next;
    }

    return NULL;
}

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
