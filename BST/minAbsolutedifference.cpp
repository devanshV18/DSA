#include<iostream>
using namespace std;

struct TreeNode {
    int value;              // Value of the node
    TreeNode* left;              // Pointer to the left child
    TreeNode* right;             // Pointer to the right child

    // Constructor to initialize the node
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};


void traverseInorder(TreeNode* root, vector<int> &nodes){
        if(root == NULL){
            return;
        }

        traverseInorder(root->left, nodes);
        nodes.push_back(root->val);
        traverseInorder(root->right, nodes);
    }


    int getMinimumDifference(TreeNode* root) {
        //no need to check null test case always ahve a minimum of 2 nodes
        vector<int> nodes;

        traverseInorder(root, nodes);

        int minDiff = INT_MAX;
        for(int i = 1; i<nodes.size(); i++){
            int diff = nodes[i] - nodes[i-1];
            minDiff = min(minDiff, diff);
        }

        return minDiff;
    }