#include<iostream>
using namespace std;


struct Node {
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};

Node* rotateRight(Node* head, int k) {
    if (head == NULL || head->next == NULL || k == 0) {
        return head; // Handle empty list, single-node list, or no rotation.
    }

    // Calculate the length of the list.
    Node* tail = head;
    int len = 1;
    while (tail->next != NULL) {
        len++;
        tail = tail->next;
    }

    // If k is a multiple of the list length, no rotation is needed.
    k = k % len;
    if (k == 0) {
        return head;
    }

    // Step 1: Make the list circular.
    tail->next = head;

    // Step 2: Find the new tail and new head, temp stores new tail. and the new head is new tail->next
    int pos = len - k; // New tail position.
    Node* temp = head;
    for (int i = 1; i < pos; i++) {
        temp = temp->next;
    }

    // Step 3: Break the circular link to form the new list.
    head = temp->next;
    temp->next = NULL;

    return head;
}