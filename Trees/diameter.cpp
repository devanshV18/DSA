#include <iostream>  // Correctly include iostream
#include <algorithm> // For max
using namespace std;

class TreeNode {
    public:
        int data;
        TreeNode* left;
        TreeNode* right;

    TreeNode(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

int height(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    int l = height(root->left);
    int r = height(root->right);

    return 1 + max(l, r); // Using max from <algorithm>
}

int diameter(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    int lst = height(root->left);  // Calculate height of the left subtree
    int rst = height(root->right); // Calculate height of the right subtree

    int currDiameter = lst + rst;  // Diameter passing through root

    int leftDiameter = diameter(root->left);  // Diameter of left subtree
    int rightDiameter = diameter(root->right); // Diameter of right subtree

    return max(currDiameter, max(leftDiameter, rightDiameter));
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(3);

    int res = diameter(root);
    cout << res << endl; // Output the result
}
