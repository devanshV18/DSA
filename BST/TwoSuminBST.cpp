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
    nodes.push_back(root->value);
    traverseInorder(root->right, nodes);
}

bool twoSum(TreeNode* root, int k){
    vector<int> nodes;
    traverseInorder(root, nodes);

    int i = 0, j = nodes.size()-1;

    while(i<j){
        int sum = nodes[i] + nodes[j];

        if( sum == k ){
            return true;
        }
        else if( sum > k ){
            j--;
        }
        else{
            i++;
        }
    }

    return false;
}