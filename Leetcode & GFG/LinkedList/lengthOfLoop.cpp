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

int lengthOfLoop(Node* head){
    unordered_map<Node*, int> m;
    Node* temp = head;
    int timer = 1;

    while(temp != NULL){
        if(m.find(temp) != m.end()){
            int value = m[temp];
            return timer - value;
        }

        m[temp] = timer;
        timer += 1;
        temp = temp -> next;
    }
    return 0;
}



    int lengthofLoopOpt(Node* head){
        Node* slow = head;
        Node* fast = head;

        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next;

            if(slow == fast){
                int count = 0;
                while(slow != fast){
                    slow = slow -> next;
                    count += 1;
                }
                return count;
            }
        }
        return 0;
    }