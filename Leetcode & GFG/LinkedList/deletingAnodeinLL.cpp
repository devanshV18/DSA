#include<iostream>
using namespace std;


//  * Definition for singly-linked list.
struct ListNode {
int val;
 ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};


void deleteNode(ListNode* node) {
    ListNode* nextNode = node->next;
    node->val = nextNode->val;
    node->next = nextNode -> next;

}