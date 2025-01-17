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
        Node* temp = head;

        while(temp != null){
            Node* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }

        return prev;
}

Node* getKThNode(Node* temp, int k){
    k -= 1;

    while(temp != NULL && k > 0){
        temp = temp->next;
        k--;
    }

    return temp;
}

Node* newHeadReverseInK(Node* head, int k){
    Node* temp = head;
    Node* prevLast = NULL;

    while(temp != NULL){
        Node* kthNode = getKThNode(temp,k);

        if(kthNode == NULL){
            if(prevLast){
                prevLast->next = temp;
            }
            break;
        }

        Node* nextNode = kthNode->next;
        kthNode->next = NULL;

        reverseList(temp);

        if(temp == head){
            head = kthNode;
        }
        else{
            prevLast->next = kthNode;
        }

        prevLast = temp;
        temp = nextNode;
    }

    return head;
}