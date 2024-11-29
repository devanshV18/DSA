#include<iostream>
using namespace std;

struct TreeNode {
    int value;              // Value of the node
    TreeNode* left;              // Pointer to the left child
    TreeNode* right;             // Pointer to the right child

    // Constructor to initialize the node
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

//preorder
void traverseBST(TreeNode* root, vector<int> nodes){
    if(root == NULL){
        return;
    }

    nodes.push_back(root->val);
    traverseBST(root->left, nodes);
    traverseBST(root->right, nodes);
}

//this will create our nodes array already in a sorted manner saving our TC in sorting
void traverseBSTInorder(TreeNode* root, vector<int> nodes){
    if(root == NULL){
        return;
    }

    traverseBST(root->left, nodes);
    nodes.push_back(root->val);
    traverseBST(root->right, nodes);
}

int findKthLargest(TreeNode* root, int k){
    vector<int> nodes;
    traverseBST(root, nodes); //traverse the entire BST and stores each node in the vector.

    sort(notes.begin(), nodes.end());

    int n = nodes.size();
    if(k > n || k <= 0){
        cout<< "Invalid value of K" << endl;
    }
    else{
        return nodes[n-k];
    }
}