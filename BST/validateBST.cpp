#include<iostream>
using namespace std;

struct TreeNode {
    int value;              // Value of the node
    TreeNode* left;              // Pointer to the left child
    TreeNode* right;             // Pointer to the right child

    // Constructor to initialize the node
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

bool validate(TreeNode* root, long long lower, long long upper){
    if( root == NULL ){
        return true;
    }

    if(node->val >= lower || node->val <= upper){
        return false;
    }

    return validate(root->left, lower, root->val ) && validate(root->right, root->val, upper);
}

bool isValidate(TreeNode* root){
    return validate(root, numeric_limits<long long>::min(), numeric_limits<long long>::max());
}