#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class node {
    public:
        int data;
        node* left;
        node* right;

    node(int d) {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

node* buildTree(node* root) {

    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);    

    if(data == -1) {
        return NULL;
    }

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);
    return root;

}
bool isLeaf(node* node){
    if(node->left == NULL && node->right ==NULL){
        return true;
    }
    return false;
}

void addLeftBoundary(node* root, vector<int> &res){
    node* curr = root->left;

    while(curr){
        if(!isLeaf(curr)) res.push_back(curr->data);
        if(curr->left) curr = curr->left;
        else curr = curr->right;
    }
}

void addRightBoundary(node* root,vector<int> &res){
    node* curr = root->right;
    vector<int> temp;

    while(curr){
        if(!isLeaf(curr)) temp.push_back(curr->data);
        if(curr->right) curr = curr->right;
        else curr = curr->left;
    }
    for(int i = temp.size()-1 ; i>=0 ; --i){
        res.push_back(temp[i]);
    }
}

void addLeaves(node* root, vector<int> &res){
    if(isLeaf(root)){
        res.push_back(root->data);
        return;
    }
    if(root->left) addLeaves(root->left, res);
    if(root->right) addLeaves(root->right, res);

}




int main(){

}