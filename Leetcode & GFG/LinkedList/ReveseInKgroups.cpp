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

Node* reverseList(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        
        while(curr != NULL){
            Node* temp = curr->next;
            curr -> next = prev;
            prev = curr;
            curr = temp;

        }
        return prev;
}

Node* getKThNode(Node* temp, int k){
    k -= 1;
    while(temp!=NULL && k>0){
        temp = temp->next;
        k--;
    }
    return temp;
}

Node* newHeadReverseInK(Node* head, int k){
    Node* temp = head;
    Node* prevLast = NULL;

    while(temp != NULL){
        Node* KThNode = getKThNode(temp, k);

        if(KThNode == NULL){
            if(prevLast){
                prevLast->next = temp;
                break;
            }
        }

        Node* nextNode = KThNode->next;
        KThNode->next = NULL;

        reverseList(temp);

        if(temp == head){
            head = KThNode;
        }
        else{
            prevLast->next = KThNode;
        }

        prevLast = temp;
        temp = nextNode;
    }

    return head;
}