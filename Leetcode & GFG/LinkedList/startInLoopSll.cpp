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


//BRUTE FORCE
Node* startInLoop(Node* head){
    Node* temp = head;
    unordered_map<Node*, int> m;
    
    while(temp != NULL){
        if(m.find(temp) != m.end()){
            return temp;
        }
        m[temp] = 1;
        temp = temp -> next;
    }
    return NULL;
}

//OPTIMISED

Node* startInLoop(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){ //while loop terminates if at any point either fast or fast -> next gets null which means the LL has no loop
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
                slow = head;
                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }

        return NULL;
        
    }

   
