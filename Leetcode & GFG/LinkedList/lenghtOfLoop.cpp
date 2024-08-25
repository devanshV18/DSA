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

        if(slow == fast){
            int count;
            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
                count++;
            }
            return count+1;
        }
    }
    return 0;
}