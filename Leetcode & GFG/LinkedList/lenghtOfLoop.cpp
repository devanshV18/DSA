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

//hashing

// int lengthOfLoop(Node* head){
//     Node* temp = head;
//     unordered_map<Node*, int> m;
//     int timer = 1;

//     while(temp != NULL){
//         if(m.find(temp) != m.end()){
//             int curTimer = m[temp];
//             return timer - curTimer;
//         }
//         m[temp] = timer;
//         temp = temp->next;
//         timer++;
//     }
//     return 0;

// }

//TH

int lengthOfLoop(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        //loop found
        if(slow == fast){
            int count = 0
            Node* temp = slow->next; //or fast
            while(temp != slow){
                temp = temp->next;
                count++;
            }
            return count+1; //if we start count at 0, if we initialise count at 1 retrun count itself
        }
    }

    //noloop
    return 0;
}