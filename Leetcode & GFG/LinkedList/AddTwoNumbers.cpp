#include<iostream>
using namespace std;
#include<unordered_map>

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

// Node* sumList(Node* l1, Node* l2){
//     Node* t1 = l1;
//     Node* t2 = l2;

//     Node* dummy = new Node(-1);
//     Node* curr = dummy;
//     int carry = 0;
    
//     while( t1 != NULL || t2 != NULL ){
//         int sum = carry; //including carry right away in the sum 
//         if(t1) sum += t1->data;
//         if(t2) sum += t2->data;

//         Node* temp = new Node(sum % 10);
//         carry = sum/10;

//         curr->next = temp;
//         curr = curr->next;

//         //checking and moving only the pointer that is not null
//         if(t1) t1 = t1->next;
//         if(t2) t2 = t2-> next;
//     }

//     //if we get a carry i.e. carry is not zero
//     if(carry){
//         Node* carryNode = new Node(carry);
//         curr->next = carryNode;
//     }

//     return dummy->next;
// }

Node* addTwoNumbers(Node* h1, Node* h2){
    Node* dummy = new Node(-1);
    Node* curr = dummy;

    Node* t1 = h1;
    Node* t2 = h2;

    int carry = 0;

    while(t1 != NULL && t2 != NULL){
        int sum = 0;
        if(t1){
            sum += t1->data;
        }
        if(t2){
            sum += t2->data;
        }

        sum += carry;

        //value to be pushed
        Node* newNode = new Node(sum % 10);

        //updating carry
        carry = sum/10;

        curr->next = newNode;
        curr = curr->next;

        if(t1) t1 = t1->next;
        if(t2) t2 = t2->next;
    }

    //once both gets null that is both list are traversed completely we simply need to check if the carry is a nonzero value and add it to the end of our sum list.

    if(carry){
        Node* newNode = new Node(carry);
        curr->next = newNode;
    }

    return dummy->next;
}