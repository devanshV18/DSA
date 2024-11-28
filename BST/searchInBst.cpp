#include<iostream>
#include<vector>
using namespace std;

struct BST {
    int value;              // Value of the node
    BST* left;              // Pointer to the left child
    BST* right;             // Pointer to the right child

    // Constructor to initialize the node
    BST(int val) : value(val), left(nullptr), right(nullptr) {}
};

bool Search(BST *root, int val){
    if(root == NULL){
        return false;
    }

    if( root->value == val){
        return true;
    }

    else if( val > root->value && root->right != NULL ){
        return Search(root->right, val);
    }
    else if( val < root->value && root->left != NULL){
        return Search(root->left, val);
    }
    else{
        return false;
    }
}