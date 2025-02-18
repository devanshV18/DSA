#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

 ListNode* removeDUplicatesFromSLL(ListNode* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    ListNode* temp = head;
    while(temp != NULL && temp->next != NULL){
        if(temp->val == temp->next->val){
            temp->next = temp->next->next;
        }
        else{
            temp = temp->next;
        }
    }

    return head;
 }