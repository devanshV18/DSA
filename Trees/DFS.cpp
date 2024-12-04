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
}


vector levelOrderTraversal(TreeNode* root){
    vector<vector<int>> ans;

    if( root == NULL ){
        return ans;
    }

    //root is not null so lets initiate the queue by pushing in the root
    queue<TreeNode> q;
    q.push(root);

    //whenever or until queue is not empty we need to process the nodes in queue.   
    while( !q.empty() ){
        int size = q.size(); //denotes the number of nodes in the queue
        vector<int> level(size);
        //the loop processes each level -> it stores each node in each level in a vector, once the level is processed completely i.e. for loop ends, just outside the for loop, we push the vector containing each node of the level into the 2D vector

        for(int i = 0; i<size; i++){
            TreeNode* node = q.front();
            q.pop();

            if(node->left){
                q.push(node->left);
            }

            if(node->right){
                q.push(node->right);
            }

            level.push_back(node->val);
        }

        ans.push_back(level);
    }

    return ans;
}

s