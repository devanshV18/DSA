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

bool hasPathSum(TreeNode* root, int target){
    if(root == NULL){
        return false;
    }
    stack<TreeNode*> path;
    stack<int> pathSum;

    path.push(root);
    pathSum.push(root->val);

    while(!path.empty()){
        TreeNode* temp = path.top();
        path.pop();
        int tempVal = pathSum.top();
        pathSum.pop();

        if(temp->left == NULL && temp->right == NULL && tempVal == target){
            return true;
        }

        if(node->left){
            path.push(temp->left);
            pathSum.push(tempVal + temp->left->data);
        }

        if(node->right){
            path.push(temp->right);
            pathSum.push(tempVal + temp->right->data);
        }
    }
    return false;
}