#include <iostream> 
#include<stack>
using namespace std;

class TreeNode {
    public:
        int data;
        TreeNode* left;
        TreeNode* right;

    TreeNode(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

bool isMirror(TreeNode* left, TreeNode* right){
    if(left == NULL && right == NULL){
        return true;
    }

    if(left == NULL || right == NULL){
        return false;
    }

    return (left->data == right->data) 
            && isMirror(left->left, right->right)
            && isMirror(left->right, right->left);
}

bool isSymmetric(TreeNode* root){
    if(root == NULL){
        return true;
    }

    return isMirror(root->left, root->right);
}