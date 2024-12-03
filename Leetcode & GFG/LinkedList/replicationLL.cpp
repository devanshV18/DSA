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
        random=nullptr;
    }
        
};


Node replicatedHead(Node* head){

    //creating new nodes with the copy of current lists
    Node* temp = head;
    unordered_map<Node, Node> nodeMap;

    while(temp != NULL){
        Node* copiedNode = new Node(temp->val);
        nodeMap[temp] = copiedNode;
        temp = temp->next;
    }

    temp = head;

    while(temp != NULL){
        Node* copiedNode = nodeMap[temp];
        copiedNode->next = nodeMap[temp->next];
        copiedNode->random = nodeMap[temp->random];
        temp = temp->next;
    }

    return nodeMap[head];
}