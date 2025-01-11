#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };


 ListNode* sortLL(ListNode* head){
    ListNode* temp = head;
    vector<int> v;

    while(temp != NULL){
        v.push_back(temp->val);
        temp = temp->next;
    }

    sort(v.begin(), v.end());

    temp = head;
    int i = 0;

    while(temp != NULL){
        temp->val = v[i];
        i++;
        temp=temp->next;
    }

    return head;
 }