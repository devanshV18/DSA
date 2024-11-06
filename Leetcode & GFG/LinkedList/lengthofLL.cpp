#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
}; 



    //Function to count nodes of a linked list.
    int getCount(struct Node* head){
        
        if(head==NULL){
            return 0;
        }
    
        int count = 1;
        Node* temp = head;
        while(temp->next!=NULL){
            temp=temp->next;
            count++;
        }
        
        return count;
    
    }

    