#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

 //BRUTE FORCE

 ListNode* deletefromLast(ListNode* head, int n){
    int cnt = 0;
    ListNode* temp = head;
    while(temp != NULL){
        cnt++;
        temp = temp->next;
    }

    //edge case - head node
    if(cnt == n){
        ListNode* newHead = head->next;
        return newHead;
    }

    int res = cnt - n;
    ListNode* temp = head;
    while(temp != NULL){
        res--;
        if(res == 0){
            break;
        }
        temp = temp->next;
    }
    ListNode* delNode = temp->next;
    temp->next = temp->next->next;
    return head;
 }

 //OPTIMISED

 ListNode* deleteNthFromLat(ListNode* head, int n){
    ListNode* fast  =head;
    for(int i = 0; i<n; i++){
        fast = fast->next;
    }

    //edge case - head node
    if(fast == NULL){
        ListNode* newHead = head->next;
    }

    ListNode* slow = head;
    while(fast->next != NULL){
        fast = fast->next;
        slow = slow->next;
    }

    ListNode* delNode = slow->next;
    slow->next = slow->next->next;
    return head;

    
 }