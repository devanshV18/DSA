#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class TreeNode {
    public:
        int data;
        TreeNode* left;
        TreeNode* right;

    TreeNode(int d) {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

// Function to check if a TreeNode is leaf or not
bool isLeaf(TreeNode* root) {
    if (root -> left == NULL && root -> right == NULL) {
        return true;
    } else {
        return false;
    }
}

// Adding left boundary
void addLeftBoundary(TreeNode* root, vector<int>& res) {
    TreeNode* current = root->left;
    while (current) {
        if (!isLeaf(current)) {
            res.push_back(current->data);
        }
        if (current->left) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
}

// Adding right boundary
void addRightBoundary(TreeNode* root, vector<int>& res) {
    TreeNode* current = root->right;
    vector<int> temp;
    while (current) {
        if (!isLeaf(current)) {
            temp.push_back(current->data);
        }
        if (current->right) {
            current = current->right;
        } else {
            current = current->left;
        }
    }

    // Reversing the right boundary nodes before adding them to result
    for (int i = temp.size() - 1; i >= 0; i--) {
        res.push_back(temp[i]);
    }
}

// Adding leaf nodes
void addLeaves(TreeNode* root, vector<int>& res) {
    if (isLeaf(root)) {
        res.push_back(root->data);
        return;
    }

    if (root->left) {
        addLeaves(root->left, res);
    }
    if (root->right) {
        addLeaves(root->right, res);
    }
}

// Main boundary traversal function
vector<int> boundaryTraversal(TreeNode* root) {
    vector<int> res;

    if (root == NULL) {
        return res;
    }

    res.push_back(root->data);

    addLeftBoundary(root, res);
    addLeaves(root, res);
    addRightBoundary(root, res);

    return res;
}

// Main function
int main() {
    // Building a binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->left->left = new TreeNode(8);
    root->left->left->right = new TreeNode(9);
    root->right->left->left = new TreeNode(10);

    // Get the boundary traversal
    vector<int> boundary = boundaryTraversal(root);

    // Print the result
    cout << "Boundary traversal of the tree: ";
    for (int i : boundary) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
