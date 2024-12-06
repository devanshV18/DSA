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

bool isIdentical(TreeNode* p, TreeNode* q){
    if(p == NULL && q == NULL){
        return true;
    }

    if(p == NULL || q == NULL){
        return false;
    }

    return(p->val == q->val) 
            && isIdentical(p->left, q->left);
            && isIdentical(p->right, q->right);
}