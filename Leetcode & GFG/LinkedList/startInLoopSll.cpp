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
    If(head == NULL || head->next == NULL){
        return NULL;
    }

    Node* temp = head;
    unordered_map<Node*, int> nmap;

    while(temp!=NULL){
        if(nmap.find(temp) != nmap.end()){
            return temp;
        }
        nmap[temp] = 1;
        temp = temp->next;
    }

    //if temp gets null, while loop breaks and it simply means there is no loop hence no start obliviously.
    return NULL;
}

//OPTIMISED

Node* startInLoop(Node* head){
    Node* slow = head;
    Node* fast = head;

    while ( fast!= NULL && fast->next != NULL ){
        slow = slow->next;
        fast = fast->next->next;

        //if loop is present
        if ( slow == fast ){
            slow = head;
            while( slow!=fast ){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }

    //if fast or fast->next gets null it means no loop present
    return NULL;

        
    }

   
// Node* temp = head;
//     unordered_map<Node*, int> m;
    
//     while(temp != NULL){
//         if(m.find(temp) != m.end()){
//             return temp;
//         }
//         m[temp] = 1;
//         temp = temp -> next;
//     }
//     return NULL;