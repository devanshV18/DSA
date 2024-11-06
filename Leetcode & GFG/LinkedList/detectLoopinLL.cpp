#include<iostream>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };


    bool hasCycle(ListNode *head) {
        if( head == NULL || head->next == NULL ){
            return false
        }

        ListNode* slow = head;
        ListNode* fast = head->next;

        while( fast != NULL || fast->next != NULL ){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                return true
            }
        }

        in case fat or fast-> next gets null means no loop
        return false;
    }