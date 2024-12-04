#include<iostream>
using namespace std;


class TreeNode{
    public:

    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int v){
        data = v;
        left = right = NULL;
    }
}

int height(TreeNode* root){
    if(root == NULL){
        return 0;
    }

    int lh = height(root->left);
    int rh = height(root->right);

    return 1 + max(lh,rh);
}