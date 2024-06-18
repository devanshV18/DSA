#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};

Node* reverseDLL(Node* head){
    if(head == NULL || head -> next == NULL){
        return head;
    }

    Node* current = head;
    Node* last = NULL;

    while(current != NULL){
        last = current -> prev;
        current -> prev = current -> next;
        current -> next = last;
        current = current -> prev;
    }

    return last -> prev;
}