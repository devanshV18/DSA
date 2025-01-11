#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

 //BRUTE FORCE
 //1 based indexing code
 ListNode* deletefromLast(ListNode* head, int n){
    if(head == NULL){
        return head;
    }

    int cnt = 0;
    ListNode* temp = head;

    while(temp != NULL){
        cnt++;
        temp = temp->next;
    }

    if(n > cnt || n<= 0){
        return head;
    }

    if(n == cnt ){
        return head->next;
    }

    int res = cnt - n;
    temp = head;

    for(int i = 1; i<res; i++){
        temp = temp->next;
    }

    ListNode* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    nodeToDelete->next = NULL;

    return head;
 }

 ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        for(int i = 0; i<n; i++){
            fast = fast->next;
        }

        if(fast == NULL){
            ListNode* newHead = head->next;
            return newHead;
        }

        ListNode* slow = head;
        while(fast!= NULL && fast->next != NULL){
            slow = slow->next;
            fast=fast->next;
        }

        ListNode* del = slow->next;
        slow->next = slow->next->next;
        return head;
    }