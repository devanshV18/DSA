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


vector<vector<int>> zigzagTraversal(TreeNode* root){
    vector<vector<int>> result;

    if(root == NULL){
        return result;
    }

    queue<TreeNode*> q;
    bool ltr = true;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        vector<int> row(size);

        for(int i = 0; i<size; i++){
            TreeNode* node = q.front();
            q.pop();

            if(node->left){
                q.push(node->left);
            }

            if(node->right){
                q.push(node->right);
            }

            int index = (ltr) ? i : size - i - 1; //deciding the direction of filling our row vector based on ltr flag
            row[index] = node->data;
        }

        //after we build one level or row = we push that row to result vector and also change the gflag to oppsite sign for next level
        ltr = !ltr;
        result.push_back(row);
    }

    return result;
}