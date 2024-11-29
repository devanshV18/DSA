#include<iostream>
using namespace std;

struct TreeNode {
    int value;              // Value of the node
    TreeNode* left;              // Pointer to the left child
    TreeNode* right;             // Pointer to the right child

    // Constructor to initialize the node
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

//leaf insertion procedure
TreeNode* insert(TreeNode* root, int val){
    if(root == NULL){
        return new TreeNode(val)
    }

    TreeNode* current = root;
    while(true){
        if(current->value <= val){ //need to go right
            if(current->right != NULL){ //checking if we can go right
                current = current->right;
            }
            else{
                current->right = new TreeNode(val);
                break;
            }
        }
        else{ //need to go left
            if(current->left != NULL){// checking if we can go left
                current = current->left;
            }
            else{
                current->left = new TreeNode(val);
                break;
            }
        }
    }
    return root;
}