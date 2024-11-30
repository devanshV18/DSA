#include<iostream>
using namespace std;


struct Node {
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};


//BRUTE FORCE

Node* sorted(Node* head){
    Node* temp = head;
    int cntZero = 0, cntOne = 0, cntTwo = 0;
    while( temp!=NULL ){
        if(temp->data == 0){
            cntZero++;
        }
        else if(temp->data == 1){
            cntOne++;
        }
        else{
            cntTwo++;
        }
        temp = temp->next;
    }

    temp = head;

    while(temp!=NULL){
        if(cntZero > 0){
            temp->data = 0;
            cntZero--;
        }
        else if(cntOne > 0){
            temp->data = 1;
            cntOne--;
        }
        else{
            temp->data = 2;
            cntTwo--;
        }
        temp = temp->next;
    }

    return head;
}


//OPTIMAL

Node* sortOptimal(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* zeroHead = new Node(-1);
    Node* zero = zeroHead;

    Node* oneHead = new Node(-1);
    Node* one = oneHead;

    Node* twoHead = new Node(-1);
    Node* two = twoHead;

    Node* temp = head;

    while( temp!=NULL ){
        if(temp->data == 0){
            zero->next = temp;
            zero = zero->next;
        }
        else if(temp->data == 1 ){
            one->next = temp;
            one = one->next;
        }
        else{
            two->next = temp;
            two = two->next;
        }
        temp = temp->next;
    }

    //after while loop ends we are at a point where one, zero and two all 3 pointers point at the last nodes of each segregated list

    //makingg link changes
    if(oneHead->next){
        zero->next = oneHead->next;
    }
    else{
        zero->next = twoHead->next;
    }

    one->next = twoHead->next;
    two->next = NULL;

    Node* newHead = zeroHead->next;

    return newHead;
}