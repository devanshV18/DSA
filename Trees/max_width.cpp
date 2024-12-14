#include<iostream>
#include<queue>
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


int maxWidth(TreeNode* root){
    if(!root){
        return 0;
    }

    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    int ans = 0;

    while(!q.empty()){
        int size = q.size();
        int first, last;
        int min = q.front().second;

        for(int i = 0; i<size; i++){
            int curr_index = q.front().second - min;
            TreeNode* node = q.front().first;
            q.pop();

            if(i == 0 ) first = curr_index;
            if( i == size - 1) last = curr_index;

            if(node->left){
                q.push({node->left, (curr_index*2 + 1)})
            }
            if(node->right){
                q.push({node->right, (curr_index*2 + 2)})
            }
        }
        ans = max(ans, first-last+1);
    }

    return ans;
}