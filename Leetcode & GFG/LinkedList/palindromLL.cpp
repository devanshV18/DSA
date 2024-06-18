#include<iostream>
#include<vector>
using namespace std;

struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};

bool isPalindrome(Node* head){
    vector<int> v;
    Node* temp = head;

    while(temp!=NULL){
        v.push_back(temp -> data);
        temp = temp -> next;
    }

    int n = v.size();
    for(int i = 0; i<n/2; i++){
        if(v[i] != v[n-i-1]){
            return false;
        }
    }

    return true;
}

