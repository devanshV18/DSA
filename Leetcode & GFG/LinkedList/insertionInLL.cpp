#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node * next;
    
    Node (int x)
    {
        data=x;
        next=nullptr;
       
    }
        
};



    //Function to insert a node at the beginning of the linked list.
    Node *insertAtBegining(Node *head, int x) {
        
    Node* newNode = new Mode(x); //created a new  Node

    if( head == NULL ){
        return newNode;
    }
    
    //pointing next of the newNode to the head
    newNode->next = head;

    //returning new head
    return newNode;
    }
    
    
    //Function to insert a node at the end of the linked list.
    Node *insertAtEnd(Node *head, int x)  {
       Node* newNode = new Node(x);

       if(head == NULL){
        return newNode;
       }

       Node* temp = head;

        //moving temp till it reaches the last node
       while( temp->next != NULL ){
        temp = temp->next;
       }
       

       //once while loop ends we've reached the last node
       temp->next = newNode;

       newNode->next = NULL;

       return head;
    }