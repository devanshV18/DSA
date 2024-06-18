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

//Deletion of Head in DLL
Node* deleteHead(Node* head){
    if(head == NULL || head -> next == NULL){ 
        return NULL;
    }

    Node* prev = head;
    head = head->next;

    head->prev = nullptr;
    prev->next = nullptr;

    delete prev;
    return head; 
}

Node* deleteTail(Node* head){

    if(head == NULL || head -> next == NULL){
        return NULL;
    }

    Node* tail = head;

    while(tail -> next != NULL){
        tail = tail -> next;
    }

    Node* prev = tail->prev;
    prev->next = nullptr;
    tail->prev = nullptr;

    delete tail;
    return head; 

}

Node* removeKthElement(Node* head, int k){
    if(head == NULL){
        return NULL;
    }

    int cnt = 0;
    Node* temp = head;

    while(temp -> next != NULL){
        cnt++;
        if(cnt == k){
            break;
        }
        temp = temp-> next;
    }

    
    Node* prev = temp->prev;
    Node* front = temp -> next;

    if(prev == NULL && front == NULL){
        return NULL; //deleting a single element
    }
    else if(prev == NULL){
        return deleteHead(head);
    }

    else if(front == NULL){
        return deleteTail(head);
    }

    else{
        prev -> next = front;
        front -> prev = prev;
        temp -> next = temp -> prev = NULL;

        delete temp;
        return head; 
    }
}