#include<iostream>
using namespace std;

struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; 


void addNode(Node *head, int pos, int data)
{
   if(head == NULL){
       return;
   }
   
   Node* x = new Node(data);
   
   Node* temp = head;
   
   
   while(pos--){
       temp = temp->next;
       
   }
   
   x->next = temp->next;
   x->prev = temp;
   if(temp -> next != NULL){
       temp -> next -> prev = x;
   }
   temp -> next = x;
   
 }