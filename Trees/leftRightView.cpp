#include<iostream>
#include<bits/stdc++.h>
#include<queue>
#include<unordered_map>
using namespace std;

class TreeNode {
    public:
        int data;
        TreeNode* left;
        TreeNode* right;

    TreeNode(int d) {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

//code for right view
vector<int> rightView(TreeNode* root){
    vector<int> res;

    if(root == NULL) return res;

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        for(int i = 0; i<size; i++){
            TreeNode* node = q.front();
            q.pop();

            if(i == size-1){
                res.push_back(node->data);
            }

            if(node->left){
                q.push(node->left);
            }

            if(node->right){
                q.push(node->right);
            }
        }
    }
    return res;
}


//code for left view
vector<int> leftView(TreeNode* root){
    vector<int> res;

    if(root == NULL) return res;

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        for(int i = 0; i<size; i++){
            TreeNode* node = q.front();
            q.pop();

            if(i == 0){
                res.push_back(node->data);
            }

            if(node->left){
                q.push(node->left);
            }

            if(node->right){
                q.push(node->right);
            }
        }
    }
    return res;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(4);
    // Get the right view
    vector<int> rightViewResult = rightView(root);
    //Get the left view
    vector<int> leftViewResult = leftView(root);

    // Print the right view
    cout << "Right view of the tree: ";
    for (int i : rightViewResult) {
        cout << i << " ";
    }
    cout << endl;

    // Print the left view   
    cout << "Left view of the tree: ";
    for (int i : leftViewResult) {
        cout << i << " ";
    }

    cout << endl;

    return 0;
}