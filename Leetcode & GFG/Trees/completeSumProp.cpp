#include<iostream>
using namespace std;
#include<bits/stdc++.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};


void isSumProperty(Node *root)
    {
        if(root == NULL){
            return;
        }
        int child = 0;
        if(root -> left){
            child += root->left->data;
        }
        if(root -> right){
            child += root->right->data;
        }
        
        if(child >= root->data) {
            root -> data = child;
        }
        
        else{
            if(root -> left){
                root->left->data = root->data;
            }
            if(root -> right){
                root->right->data = root->data;
            }
        }
        
        isSumProperty(root -> left);
        isSumProperty(root -> right);
        
        int tot = 0;
        if(root -> left){
            tot += root->left->data;
        }
        if(root -> right){
            tot += root->right->data;
        }
        if(root -> left || root -> right){
            root -> data = tot;
        }
    }

    int main(){

    }