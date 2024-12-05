#include<iostream>
#include<bits/stdc++.h>
#include<queue>
#include<unordered_map>
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

// Function to get the bottom view of the binary tree
vector<int> bottomView(TreeNode* root) {
    vector<int> res;

    if (root == NULL) {
        return res;
    }

    queue<pair<TreeNode*, int>> q; // Queue to store node and horizontal distance
    unordered_map<int, int> m; // Map to store the last node at each horizontal distance

    q.push({root, 0}); // Start with the root at horizontal distance 0

    while (!q.empty()) {
        auto it = q.front();
        q.pop();

        TreeNode* node = it.first;
        int line = it.second;

        m[line] = node->data; // Update the bottommost node for each horizontal distance

        if (node->left) {
            q.push({node->left, line - 1}); // Move left child to horizontal distance - 1
        }

        if (node->right) {
            q.push({node->right, line + 1}); // Move right child to horizontal distance + 1
        }
    }

    // Sort the map by horizontal distance (key) and push the values to result
    vector<pair<int, int>> sorted(m.begin(), m.end());
    sort(sorted.begin(), sorted.end());

    for (auto it : sorted) {
        res.push_back(it.second); // Add the node values in sorted order
    }

    return res;
}

// Main function to test the bottom view logic
int main() {
    // Creating a binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->left->left = new TreeNode(8);
    root->right->left->right = new TreeNode(9);

    // Get the bottom view
    vector<int> bottomViewResult = bottomView(root);

    // Print the result
    cout << "Bottom view of the tree: ";
    for (int i : bottomViewResult) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
