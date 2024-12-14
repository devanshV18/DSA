#include<iostream>
using namespace std;


class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int v){
        data = val;
        right = left = NULL;
    }
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //Base case
        if(root == NULL || root == p || root == q){
            return root;
        }

        //RC
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);

        //processing -> happens after all rc is done for a node -> to initiate BAcktracking

        //logic -> to return not null from the received pair.
        if( left == NULL ){
            return right;
        }

        if( right == NULL ){
            return left;
        }

        //VVVVVIII 
        //when a node receives both not nulls (from RC) we return the root (The core logic)
        //the core logic says, if a node has receiver two not nulls (i.e left!=NULL and right != NULL) from RC.
        //it means that the receiving node is under the path of both the pair of nodes for which lca is to be determined, so we process that node to returning the node itself to the preceeding node or say backtracking
        return root;
    }