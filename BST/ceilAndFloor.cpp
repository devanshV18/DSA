#include<iostream>
using namespace std;

struct TreeNode {
    int value;              // Value of the node
    TreeNode* left;              // Pointer to the left child
    TreeNode* right;             // Pointer to the right child

    // Constructor to initialize the node
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

int ceil(TreeNode* root, int x){
    if(root == NULL){
        return -1;
    }

    int ceil = -1;

    while(root){
        if(root->value == x){
            ceil = root->value;
            return ceil;
        }

        if( root->value < x ){
            root = root->right;
        }
        else{
            ceil = root->value;
            root = root->left;
        }
    }

    return ceil;
}

int floor(TreeNode* root, int x){
    if( root == NULL ){
        return -1;
    }

    int floor = -1;

    while(root){
        if(root->value == x){
            floor = root->value;
            return floor;
        }
        if(root->value > x ){
            root = root->left;
        }
        else{
            floor = root->value;
            root = root->right;
        }
    }
    return floor;
}