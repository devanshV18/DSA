#include<iostream>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

 Node* sortedList(node* list1, Node* list2){
    if( list1 == NULL ) return list2;
    if( list2 == NULL ) return list1;
    Node* ptr1 = list1;
    Node* ptr2 = list2;
    Node* dummy = new Node(-1);
    Node* ptr3 = dummy;

    while( ptr1 != NULL && ptr2 != NULL ){
        if(ptr1->val < ptr2->val){
            ptr3->next = ptr1;
            ptr1 = ptr1->next;
        }
        else{
            ptr3->next = ptr2;
            ptr2 = ptr2->next;
        }
        
        ptr3 = ptr3->next;
    }

    while(ptr1 != NULL){
        ptr3->next = ptr1;
        ptr1 = ptr1->next;
        ptr3 = ptr3->next;
    }

    while(ptr2 != NULL){
        ptr3->next = ptr2;
        ptr2 = ptr2->next;
        ptr3 = ptr3->next;
    }

    return dummy->next;
 }