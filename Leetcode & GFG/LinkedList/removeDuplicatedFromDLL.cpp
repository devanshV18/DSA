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

Node* removedDuplicates(Node* head){

     Node* temp = head;

     while( temp != NULL && temp->next != NULL ){
        Node* nextNode = temp->next;
        while( nextNode != NULL && nextNode->data == temp->data ){
            Node* duplicate = nextNode;
            nextNode = nextNode->next;
            delete(duplicate);
        }
        temp->next = nextNode;
        if(nextNode) nextNode->prev = temp;
        temp = temp->next;
     }

     return head;
}

Node* removeDuplicatesfromDLL(Node* head){
    Node* temp = head;

    //the condition for the while loop to work.
    while(temp!= NULL && temp->next != NULL){
        Node* nextNode = temp->next;
        //the below condition is chosen, as nextNode can reach null as well in the process of traversing duplicates, so if nextNode only moves until it is not null and the data at nextNode is equal to the temp->data. If ay any point the data is differed we get a unique node and in case nextNode reaches NULL we again get a differed node say end of the list.
        while(nextNode != NULL && nextNode->data == temp->data){
            Node* duplicate = nextNode;
            nextNode = nextNode->next;
            delete(duplicate);
        }

        //when internal while loop terminates, we have reached either a unique node or the end of the list, hence further logic is handled as:-

        temp->next = nextNode;
        if(nextNode != NULL) nextNode->prev = temp;

        temp = temp->next;
    }
}