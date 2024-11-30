#include<iostream>
using namespace std;

struct TreeNode {
    int value;              // Value of the node
    TreeNode* left;              // Pointer to the left child
    TreeNode* right;             // Pointer to the right child

    // Constructor to initialize the node
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

int minNode(TreeNode* root){
    if(root == NULL){
        throw runtime_error("Empty BST");
    }

    TreeNode* current = root;

    while( current->left != NULL){
        current = current->left;
    }

    return current->value;
}

int maxNode(TreeNode* root){
    if(root == NULL){
        throw runtime_error("Empty BST");
    }

    treeNode* current = root;

    while( current->right != NULL ){
        current = current->right;
    }

    return current->value;
}