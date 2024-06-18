#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;

  Node(int x){
      data = x;
      next = NULL;
      prev = NULL;
  }

};

Node* deleteMidOfSLL(Node* head){
    if(head == NULL && head -> next == NULL){
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;

    while(fast != NULL && fast -> next != NULL){
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }

    prev -> next = slow -> next;
    slow -> next = NULL;

    delete slow;
    return head;

}