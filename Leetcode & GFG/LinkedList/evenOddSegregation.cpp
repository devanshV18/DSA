#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

 //BRUTE FORCE 


ListNode* segregateOddEven(ListNode* head){
    if( head == NULL || head->next == NULL){
        return head;
    }

    ListNode* temp = head;
    vector<int> v;
    while(temp != NULL && temp->next != NULL){
        v.push_back(temp->val);
        temp = temp->next->next;
    }

    if(temp){
        v.push_back(temp->val);
    }

    ListNode* temp = head->next;

    while(temp != NULL && temp->next != NULL){
        v.push_back(temp->val);
        temp = temp->next->next;
    }

    if(temp){
        v.push_back(temp->val);
    }

    ListNode* temp = head;
    int i = 0;
    while(temp != NULL){
        temp->val = v[i];
        i++;
        temp = temp->next;
    }

    return head;

}


//OPTIMISED

ListNode* segregation(ListNode* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    ListNode* odd = head;
    ListNode* even = head->next;
    ListNode* evenHead = head->next;

    while(even!=NULL && even->next!=NULL){
        odd->next = odd->next->next;
        odd = odd->next;

        even->next = even->next->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}