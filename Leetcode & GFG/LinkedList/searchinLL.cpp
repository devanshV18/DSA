#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
}; 


    // Function to count nodes of a linked list.
    bool searchKey(int n, struct Node* head, int key) {
        if(head == NULL){
            return false;
        }
        
        Node* temp = head;
        while(temp!=NULL){
            if(temp->data == key){
                return true;
            }
            temp = temp->next;
        }
    }