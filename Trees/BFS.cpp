#include<iostream>
using namespace std;
#include<vector>
#include<queue>

class TreeNode{
    public:

    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int v){
        data = v;
        right = left = NULL;
    }
};


vector<vector<int>> levelOrderTraversal(TreeNode* root){
    vector<vector<int>> result; // the vector containing answers or each level of nodes.
    if( root == NULL ){
        return result;
    }

    queue<TreeNode*> q;

    q.push(root); //initially pushing root to the queue.

    while(!q.empty()){
        int size = q.size();
        vector<int> row;

        for(int i = 0; i<size; i++){
            TreeNode* node = q.front();
            q.pop();

            if(node->left){
                q.push(node->left);
            }

            if(node->right){
                q.push(node->right);
            }

            row.push_back(node->data);
        }

        result.push_back(row);
    }

    return result;
}

