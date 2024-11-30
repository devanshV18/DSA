#include<iostream>
using namespace std;

struct TreeNode {
    int value;              // Value of the node
    TreeNode* left;              // Pointer to the left child
    TreeNode* right;             // Pointer to the right child

    // Constructor to initialize the node
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

TreeNode* findLCA(TreeNode* root, TreeNode* p, TreeNode* q){
    if(root == NULL){
        return NULL;
    }

    while(root){
        if(p->val < root->val && q->val < root->val){
        root = root->left;
    }
    else if(p->val > root->val && q->val > root->val){
        root = root->right;
    }
    else{
        return root;
    }
    }

    return NULL;

}