include<iostream>
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

int height(TreeNode* root, bool &ans){
    if( root == NULL ){
        return 0;
    }

    int lh = height(root->left, ans);
    int rh = height(root->right, ans);

    if(abs(lh-rh) > 1){
        return false;
    }

    return max(lh,rh) + 1;
}


bool isBalanced(TreeNode* root){
    if(root == NULL){
        return true;
    }

    bool ans = true;
    height(root, ans);
    return ans;
}
